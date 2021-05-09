# -*- coding: utf-8 -*-
# Usage: python image_to_text_converter.py <path to input image (.jpg, .png)> <path to output image in text format (.txt)>
__author__ = 'ZFTurbo: https://kaggle.com/zfturbo'

import cv2
import cv2
import glob, os
import numpy as np

x=1
in_path = r"E:\soc-repo\VGG16-Pretrained-C-master\ILSVRC2012_img_val"
out_save = os.path.join(r"E:\soc-repo\VGG16-Pretrained-C-master\ILSVRC2012_img_val_txt")
os.mkdir(out_save)

for infile in glob.glob(in_path+ "\\" + "*.jpeg"):

    img = cv2.imread(infile)
    if img.shape != (224, 224, 3):
        img = cv2.resize(img, (224, 224), interpolation=cv2.INTER_LANCZOS4)

    f = open(out_save +r'\ILSVRC2012_val' +"_"+ str(x) + ".txt", "x")
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            for k in range(img.shape[2]):
                f.write(str(img[i, j, k]) + " ")
        f.write("\n")

    f.close()
    print(x,'.image completed!!!!!!')
    x = x + 1




