import sys

month_name_to_number = dict(Jan=1, Feb=2, Mar=3, Apr=4, May=5, Jun=6, Jul=7, Aug=8, Sep=9, Oct=10, Nov=11, Dec=12)

def to_months(s):
    month, year = s.split()
    return (int(year) * 12) + month_name_to_number[month]

for line in open(sys.argv[1]):
    months = 0
    previous_end = 0
    for start, end in sorted((to_months(start), to_months(end))
                                for start, end in [pair.split('-')
                                    for pair in line.strip().split('; ')]):
        if start > previous_end:
            months += end - start + 1
        elif end > previous_end or start == previous_end:
            months += end - previous_end
        else:
            continue
        previous_end = end

    print(months // 12)


## datetime is slower and uses more memory than the simple convert to months
## code above.
#import sys
#from datetime import datetime
#
#for line in open(sys.argv[1]):
#    date_pairs = sorted([(datetime.strptime(start, '%b %Y'),
#                          datetime.strptime(end, '%b %Y'))
#                            for start, end in [pair.split('-')
#                                for pair in line.strip().split('; ')]])
#
#    months = 0
#    previous_end = None
#    for start, end in date_pairs:
#        if previous_end is None or start > previous_end:
#            months += (end.year*12 + end.month) - (start.year*12 + start.month) + 1
#        elif end > previous_end or start == previous_end:
#            months += (end.year*12 + end.month) - (previous_end.year*12 + previous_end.month)
#        else:
#            continue
#
#        previous_end = end
#
#    print(months // 12)
