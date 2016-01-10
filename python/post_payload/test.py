# -*- coding: utf-8 -*-

import requests
from img_upload import API
from img_upload import File

img_pth = r"01.jpg"
url = r"http://taikor_cv.zhuyeba.net/"


api = API("", "", url)

api.upload(img = File('01.jpg'))
