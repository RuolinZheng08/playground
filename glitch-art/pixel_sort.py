import numpy as np
from PIL import Image
from pixel_utils import pad_to_square

def pixel_sort(imgobj, step_size=8):
  # always sort by rows
  padded = pad_to_square(imgobj)
  data = np.array(padded)
  stripes = np.split(data, data.shape[0] // step_size, axis=0)
  sorted_data = []
  for stripe in stripes:
    sorted_data.append(np.sort(stripe, axis=0))
  sorted_arr = np.array(sorted_data)
  sorted_arr = sorted_arr.reshape(padded.height, padded.width, 3)
  sorted_arr = sorted_arr[:imgobj.height, :imgobj.width, :]  # remove padding
  return Image.fromarray(sorted_arr)