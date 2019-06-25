import numpy as np
from pixel_utils import gen_offset

# same functionality as chromatic_aberration but without PIL

def rgb_multiply_np(array):
  """np equivalent of rgb_multiply"""
  red, green, blue = np.copy(array), np.copy(array), np.copy(array)
  red[:, :, [1, 2]] = 0
  green[:, :, [0, 2]] = 0
  blue[:, :, :2] = 0
  return red, green, blue

def offset_array(array, xoffset, yoffset):
  """Same as ImageChops.offset(imgobj, xoffset, yoffset)"""
  shifted = np.concatenate((array[:, -xoffset:, :], array[:, :-xoffset, :]), 
                           axis=1)
  shifted = np.concatenate((shifted[-yoffset:, :, :], shifted[:-yoffset, :, :]), 
                           axis=0)
  return shifted

def screen_np(a, b):
  """screen(A, B) 1 − (1 − A) * (1 − B)"""
  return 255 - (255 - a) * (255 - b)

def color_shift_np(shift_arr, other_arrs, offset):
  """np equivalent of color_shift"""
  shift_arr = offset_array(shift_arr, *offset)
  screened = screen_np(*other_arrs)
  result = screen_np(screened, shift_arr)
  return result

def chromatic_aberration_np(imgarr):
  """np equivalent of chromatic_aberration"""
  offset = gen_offset(imgarr.shape[1], imgarr.shape[0])  # width, height
  red, green, blue = rgb_multiply_np(imgarr)
  r_res = color_shift_np(red, [green, blue], offset)
  g_res = color_shift_np(green, [red, blue], offset)
  b_res = color_shift_np(blue, [red, green], offset)
  return r_res, g_res, b_res