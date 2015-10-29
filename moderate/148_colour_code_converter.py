import sys
from colorsys import hls_to_rgb, hsv_to_rgb

def CMYK_to_RGB(cmyk):
    C, M, Y, K = cmyk
    return (int(round(255 * (1-C) * (1-K))),
            int(round(255 * (1-M) * (1-K))),
            int(round(255 * (1-Y) * (1-K))))

def hex_to_RGB(hex_string):
    return(int(hex_string[1:3], 16),
           int(hex_string[3:5], 16),
           int(hex_string[5:7], 16))

def HSL_to_RGB(hsl):
    H = hsl[0] / 360.0
    S = hsl[1] / 100.0
    L = hsl[2] / 100.0
    return tuple(int(round(value * 255.0)) for value in hls_to_rgb(H, L, S))

def HSV_to_RGB(hsv):
    H = hsv[0] / 360.0
    S = hsv[1] / 100.0
    V = hsv[2] / 100.0
    return tuple(int(round(value * 255)) for value in hsv_to_rgb(H, S, V))


for line in (l.strip() for l in open(sys.argv[1])):
    if line.startswith('#'):
        print('RGB({},{},{})'.format(*hex_to_RGB(line)))
    elif line.startswith('('):
        print('RGB({},{},{})'.format(*CMYK_to_RGB(eval(line))))
    elif line.startswith('HSV'):
        print('RGB({},{},{})'.format(*HSV_to_RGB(eval(line[3:]))))
    else:
        print('RGB({},{},{})'.format(*HSL_to_RGB(eval(line[3:]))))
