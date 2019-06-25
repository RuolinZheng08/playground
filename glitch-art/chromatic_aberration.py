from PIL import Image, ImageChops
from pixel_utils import gen_offset

def rgb_multiply(imgobj):
  red = Image.new('RGB', imgobj.size, (255, 0, 0))
  red = ImageChops.multiply(imgobj, red)
  green = Image.new('RGB', imgobj.size, (0, 255, 0))
  green = ImageChops.multiply(imgobj, green)
  blue = Image.new('RGB', imgobj.size, (0, 0, 255))
  blue = ImageChops.multiply(imgobj, blue)
  return red, green, blue

def color_shift(shift_img, other_imgs, offset):
  shift_img = ImageChops.offset(shift_img, *offset)
  screened = ImageChops.screen(*other_imgs)
  result = ImageChops.screen(screened, shift_img)
  return result

def chromatic_aberration(imgobj):
  '''Return RGB Image objects'''
  offset = gen_offset(*imgobj.size)
  red, green, blue = rgb_multiply(imgobj)
  r_res = color_shift(red, [green, blue], offset)
  g_res = color_shift(green, [red, blue], offset)
  b_res = color_shift(blue, [red, green], offset)
  return r_res, g_res, b_res