# Glitch Art

This is a command line tool for generating glitch art images from `.jpeg, .jpg, .png` files. The two glitch modes are chromatic aberration and pixel sorting.

## Dependencies

Please make sure to have `numpy` and `PIL` installed.

## Usage

`./glitch_art.py -f [file | directory] -m [chromatic | sort | both]`

For example, suppose there is a directory named `images/`. Running `./glitch_art.py -f images/` will apply both chromatic aberration and pixel sorting to all image files in it. The resultant images will have the prefix `glitched_`.

If there is a single image file named `img.jpg`, run `./glitch_art.py -f img.jpg`.

## Samples

Left: the original image, right: the glitched image.

### Pixel Sorting

`./glitch_art.py -f img.jpg -m sort`

<span>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/1.jpg" style="width: 350px;"/>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/glitched_1.jpg" style="width: 350px;"/>
</span>

<span>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/2.jpg" style="width: 350px;"/>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/glitched_2.jpg" style="width: 350px;"/>
</span>

### Chromatic Aberration

`./glitch_art.py -f img.jpg -m chromatic`

<span>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/3.jpg" style="width: 350px;"/>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/glitched_3.jpg" style="width: 350px;"/>
</span>

<span>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/4.jpg" style="width: 350px;"/>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/glitched_4.jpg" style="width: 350px;"/>
</span>


### Chromatic Aberration & Pixel Sorting

`./glitch_art.py -f img.jpg -m both`

<span>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/5.jpg" style="width: 350px;"/>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/glitched_5.jpg" style="width: 350px;"/>
</span>

<span>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/6.jpg" style="width: 350px;"/>
  <img src="https://ruolinzheng08.github.io/images/glitch-art/glitched_6.jpg" style="width: 350px;"/>
</span>
## Notes

Sometimes, due to image dimension bugs, the program will skip certain files. Please change the height of the image to be a more regular number (such as 400, 800, etc.) and try running the program again.