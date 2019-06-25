import numpy as np
from PIL import Image

def gen_offset(width, height):
  """Generate random offset based on the image dimensions"""
  x, y = 0, 0
  while np.abs(x) < width // 20 or np.abs(y) < height // 20:
    # make sure offsets are tangible
    x = np.random.randint(-width // 10, width // 10)
    y = np.random.randint(-height // 10, height // 10)
  return x, y

def pad_to_square(imgobj):
  """Pad to the nearest 100th"""
  square = Image.new('RGB', ((imgobj.width // 100 + 1) * 100,
    (imgobj.height // 100 + 1) * 100), (0, 0, 0))
  square.paste(imgobj, imgobj.getbbox())
  return square