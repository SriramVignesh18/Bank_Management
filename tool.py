import keras
import cv2
import numpy as np
import sys
loc=sys.argv[1]
task=sys.argv[2]
img=cv2.imread(loc)
def super_res(image):
  if image.shape!=(64,64,3):
    image=cv2.resize(image,(64,64))
  img=image/127.5-1.
  img=img.reshape(1,img.shape[0],img.shape[1],img.shape[2])
  json_file=open("superres/generator.json","r")
  loaded_model_json=json_file.read()
  json_file.close()
  superres_genmodel=keras.models.model_from_json(loaded_model_json)
  superres_genmodel.load_weights("superres/generator.weights.h5")
  predimg=superres_genmodel.predict(img)
  predimg=predimg.reshape(predimg.shape[1:])
  predimg=(predimg+1)*127.5
  predimg=predimg.astype("uint8")
  cv2.imwrite("originalimg.jpg",image)
  cv2.imwrite("predimgsuperres.jpg",predimg)
def img_inpainting(image):
  json_file=open("inpainting/generator.json","r")
  loaded_model_json=json_file.read()
  json_file.close()
  inpainting_genmodel=keras.models.model_from_json(loaded_model_json)
  inpainting_genmodel.load_weights("inpainting/generator.weights.h5")
  def mask_randomly(imgs):
    img_rows=32
    img_cols=32
    mask_height=8
    mask_width=8
    y1=np.random.randint(0,img_rows-mask_height+1,imgs.shape[0])
    y2=y1+mask_height
    x1=np.random.randint(0,img_cols-mask_width+1,imgs.shape[0])
    x2=x1+mask_width
    masked_imgs=np.empty_like(imgs)
    missing_parts=np.empty((imgs.shape[0],mask_height,mask_width,3))
    for i,img in enumerate(imgs):
      masked_img=img.copy()
      _y1,_y2,_x1,_x2=y1[i],y2[i],x1[i],x2[i]
      missing_parts[i]=masked_img[_y1:_y2,_x1:_x2,:].copy()
      masked_img[_y1:_y2,_x1:_x2,:]=0
      masked_imgs[i]=masked_img
    return(masked_imgs,missing_parts,(y1,y2,x1,x2))
  if image.shape!=(32,32,3):
    image=cv2.resize(image,(32,32))
  img2=image.reshape(1,image.shape[0],image.shape[1],image.shape[2])
  img2=img2/127.5-1.
  masked_imgs,missing_parts,(y1,y2,x1,x2)=mask_randomly(img2)
  predimg=inpainting_genmodel.predict(masked_imgs)
  predimgreshape=predimg.reshape(predimg.shape[1],predimg.shape[2],predimg.shape[3])
  newpred=(predimgreshape+1)*127.5
  newpreduint=newpred.astype("uint8")
  masked_imgreshape=masked_imgs.reshape(masked_imgs.shape[1],masked_imgs.shape[2],masked_imgs.shape[3])
  masked_img2=(masked_imgreshape+1)*127.5
  masked_img2=masked_img2.astype("uint8")
  cv2.imwrite("maskedimage.jpg",masked_img2)
  masked_img2[y1[0]:y2[0],x1[0]:x2[0],:]=newpreduint
  cv2.imwrite("predictedimage_inpainting.jpg",masked_img2)
if task=="inpainting":
  print("Performing inpainting on image")
  img_inpainting(img)
elif task=="superresolution":
  print("Performing superresolution on image")
  super_res(img)
else:
  print("Enter the right task please: inpainting or superresolution")