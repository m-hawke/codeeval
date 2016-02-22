import sys

pi_digits = ''.join('''3141592653589793238462643383279502884197169399375105
82097494459230781640628620899862803482534211706798
21480865132823066470938446095505822317253594081284
81117450284102701938521105559644622948954930381964
42881097566593344612847564823378678316527120190914
56485669234603486104543266482133936072602491412737
24587006606315588174881520920962829254091715364367
89259036001133053054882046652138414695194151160943
30572703657595919530921861173819326117931051185480
74462379962749567351885752724891227938183011949129
83367336244065664308602139494639522473719070217986
09437027705392171762931767523846748184676694051320
00568127145263560827785771342757789609173637178721
46844090122495343014654958537105079227968925892354
20199561121290219608640344181598136297747713099605
18707211349999998372978049951059731732816096318595
02445945534690830264252230825334468503526193118817
10100031378387528865875332083814206171776691473035
98253490428755468731159562863882353787593751957781
85778053217122680661300192787661119590921642019893
80952572010654858632788659361533818279682303019520
35301852968995773622599413891249721775283479131515
57485724245415069595082953311686172785588907509838
17546374649393192550604009277016711390098488240128
58361603563707660104710181942955596198946767837449
44825537977472684710404753464620804668425906949129
33136770289891521047521620569660240580381501935112
53382430035587640247496473263914199272604269922796
78235478163600934172164121992458631503028618297455
57067498385054945885869269956909272107975093029553
21165344987202755960236480665499119881834797753566
36980742654252786255181841757467289097777279380008
16470600161452491921732172147723501414419735685481
61361157352552133475741849468438523323907394143334
54776241686251898356948556209921922218427255025425
68876717904946016534668049886272327917860857843838
27967976681454100953883786360950680064225125205117
39298489608412848862694560424196528502221066118630
67442786220391949450471237137869609563643719172874
67764657573962413890865832645995813390478027590099
46576407895126946839835259570982582262052248940772
67194782684826014769909026401363944374553050682034
96252451749399651431429809190659250937221696461515
70985838741059788595977297549893016175392846813826
86838689427741559918559252459539594310499725246808
45987273644695848653836736222626099124608051243884
39045124413654976278079771569143599770012961608944
16948685558484063534220722258284886481584560285060
16842739452267467678895252138522549954666727823986
45659611635488623057745649803559363456817432411251
50760694794510965960940252288797108931456691368672
28748940560101503308617928680920874760917824938589
00971490967598526136554978189312978482168299894872
26588048575640142704775551323796414515237462343645
42858444795265867821051141354735739523113427166102
13596953623144295248493718711014576540359027993440
37420073105785390621983874478084784896833214457138
68751943506430218453191048481005370614680674919278
19119793995206141966342875444064374512371819217999
83910159195618146751426912397489409071864942319615
67945208095146550225231603881930142093762137855956
63893778708303906979207734672218256259966150142150
30680384477345492026054146659252014974428507325186
66002132434088190710486331734649651453905796268561
00550810665879699816357473638405257145910289706414
01109712062804390397595156771577004203378699360072
30558763176359421873125147120532928191826186125867
32157919841484882916447060957527069572209175671167
22910981690915280173506712748583222871835209353965
72512108357915136988209144421006751033467110314126
71113699086585163983150197016515116851714376576183
51556508849099898599823873455283316355076479185358
93226185489632132933089857064204675259070915481416
54985946163718027098199430992448895757128289059232
33260972997120844335732654893823911932597463667305
83604142813883032038249037589852437441702913276561
80937734440307074692112019130203303801976211011004
49293215160842444859637669838952286847831235526582
13144957685726243344189303968642624341077322697802
80731891544110104468232527162010526522721116603966
65573092547110557853763466820653109896526918620564
76931257058635662018558100729360659876486117910453
34885034611365768675324944166803962657978771855608
45529654126654085306143444318586769751456614068007
00237877659134401712749470420562230538994561314071
12700040785473326993908145466464588079727082668306
34328587856983052358089330657574067954571637752542
02114955761581400250126228594130216471550979259230
99079654737612551765675135751782966645477917450112
99614890304639947132962107340437518957359614589019
38971311179042978285647503203198691514028708085990
48010941214722131794764777262241425485454033215718
53061422881375850430633217518297986622371721591607
71669254748738986654949450114654062843366393790039
76926567214638530673609657120918076383271664162748
88800786925602902284721040317211860820419000422966
17119637792133757511495950156604963186294726547364
25230817703675159067350235072835405670403867435136
22224771589150495309844489333096340878076932599397
8054193414473774418426312986080998886874132604721'''.split())

for line in sys.stdin:
    print(pi_digits[int(line)-1])
