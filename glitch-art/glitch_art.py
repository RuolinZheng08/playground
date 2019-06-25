#!/usr/bin/env python3

import os
import sys
import argparse
from PIL import Image

from divisors import *
from pixel_sort import *
from pixel_utils import *
from chromatic_aberration import *
from chromatic_aberration_np import *

def parse_args():
  """
  Parse command line arguments
  ./glitch_art --file [filename | dirname] --mode [chromatic | sort | both]
  """
  parser = argparse.ArgumentParser()
  parser.add_argument('-f', '--file', type=str)
  parser.add_argument('-m', '--mode', type=str)
  args = parser.parse_args()
  if args.file is None:
    print('Error: No file or directory specified.', file=sys.stderr)
    sys.exit(1)
  return args

def random_glitch(imgobj, step_size=2):
  """
  Combine color aberration and pixel sorting randomly
  """
  padded = pad_to_square(imgobj)
  data = np.array(padded)

  stripes = np.split(data, data.shape[0] // step_size, axis=0)
  sorted_data = []
  for stripe in stripes:
    rgblist = chromatic_aberration_np(stripe)
    all_choices = list(rgblist) + [stripe, ]
    sorted_four = [np.sort(elm, axis=0) for elm in all_choices]
    all_choices.extend(sorted_four)  # 8 possibilities
    # randomly choose from r, g, b, original & original vs. sorted
    idx = np.random.randint(0, 8)
    choice = all_choices.pop(idx)
    sorted_data.append(choice)
    
  sorted_arr = np.array(sorted_data)
  sorted_arr = sorted_arr.reshape(padded.height, padded.width, 3)
  sorted_arr = sorted_arr[:imgobj.height, :imgobj.width, :]
  
  return Image.fromarray(sorted_arr)

def glitch_image(fname, mode):
  """
  Return a glitched image object according to the mode specified
  """
  orginal, step_size = None, None
  if fname.endswith('.jpg') or fname.endswith('.jpeg') or fname.endswith('.png'):
    original = Image.open(fname)
    # randomly generate a step size that divides the image's height
    divisors = list(gen_divisors(original.height))
    idx = np.random.choice(len(divisors))
    step_size = divisors[idx]
    print('Processing ' + fname)
  else:
    print(fname + ' is not a valid image file.')
    return None

  try:
    if mode == 'chromatic':
      res = chromatic_aberration(original)
      idx = np.random.choice(2)  # return r, g, or b by chance
      return res[idx]
    elif mode == 'sort':
      return pixel_sort(original, step_size=step_size)
    # use both chromatic aberration and pixel sorting by default
    else:
      return random_glitch(original, step_size=step_size)
  except:
    print('Dimension errors processing ' + fname + ' Please try again.')
    return None

def main():
  args = parse_args()
  if not os.path.exists(args.file):
    print("Error: File doesn't exist.")
    sys.exit(1)
  if os.path.isdir(args.file):
    files = os.listdir(args.file)
    for f in files:
        glitched = glitch_image(args.file + f, args.mode)
        if glitched is not None:
          glitched.show()
          glitched.save(args.file + 'glitched_' + f)
  elif os.path.isfile(args.file):
    glitched = glitch_image(args.file, args.mode)
    if glitched is not None:
      glitched.show()
      dirname, fname = os.path.split(args.file)
      glitched.save(dirname + '/glitched_' + fname)
  print('Finished processing files.')
      
if __name__ == '__main__':
  main()