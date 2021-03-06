init offset = -1

# Glossary Screen
screen glossary():
  tag menu
  use game_menu(_("Glossary")):
    hbox spacing 100:

      viewport:
        xsize 250 ysize 500
        child_size (None, 4000)
        scrollbars 'vertical'
        spacing 5
        draggable True
        mousewheel True
        arrowkeys True

        vbox spacing 20:
          for word in sorted(glossary_dict.keys()):
            if word in persistent.unlocked_glossary:
              textbutton word action SetVariable("word_in_display", word)
            else:
              textbutton word action NullAction()
      vbox xsize 550 ysize 500 box_wrap True:
        text glossary_dict.get(word_in_display, "")

# CG Gallery Screen
screen gallery():
  tag menu
  use game_menu(_("Gallery"))

# Dict and List variables used for Glossary and Gallery
init -1 python:
  persistent.unlocked_glossary = set()
  persistent.unlocked_gallery = set()

  # The current word in display on the Glossary screen
  word_in_display = ""

  # A list of unlockable gallery images
  gallery_list = []

  # Words and definitions generated by https://www.wordgenerator.net/random-word-generator.php
  glossary_dict = {
  'Acidimetry': 'The measurement of the strength of acids especially by a '
               'chemical process based on the law of chemical combinations or '
               'the fact that to produce a complete reaction a certain '
               'definite weight of reagent is required',
  'Acoustic': 'Pertaining to the sense of hearing the organs of hearing or the '
             'science of sounds auditory',
  'Acquiesce': 'To rest satisfied or apparently satisfied or to rest without '
              'opposition and discontent usually implying previous opposition '
              'or discontent to accept or consent by silence or by omitting to '
              'object followed by in formerly also by with and to',
  'Acrimoniousness': 'The quality of being acrimonious asperity acrimony',
  'Adjacence': 'The state or attribute of being adjacent or contiguous '
              'contiguity the attribute of being so near as to be touching as '
              'the adjacency of lands or buildings',
  'Aufklaumlrung': 'A philosophic movement of the 18th century characterized by '
                  'a lively questioning of authority keen interest in matters '
                  'of politics and general culture and an emphasis on '
                  'empirical method in science It received its impetus from '
                  'the unsystematic but vigorous skepticism of Pierre Bayle '
                  'the physical doctrines of Newton and the epistemological '
                  'theories of Locke in the preceding century Its chief center '
                  'was in France where it gave rise to the skepticism of '
                  'Voltaire the naturalism of Rousseau the sensationalism of '
                  'Condillac and the publication of the ldquoEncyclopediardquo '
                  'by DAlembert and Diderot In Germany Lessing Mendelssohn and '
                  'Herder were representative thinkers while the political '
                  'doctrines of the leaders of the American Revolution and the '
                  'speculations of Benjamin Franklin and Thomas Paine '
                  'represented the movement in America',
  'Barocyclonometer': 'An aneroid barometer for use with accompanying graphic '
                     'diagrams and printed directions designed to aid mariners '
                     'to interpret the indications of the barometer so as to '
                     'determine the existence of a violent storm at a distance '
                     'of several hundred miles',
  'Belletristic': 'Occupied with or pertaining to belles lettres',
  'Big ticket': 'same as expensive but in an absolute sense referring to items '
               'of a type which are all expensive such as automobiles '
               'refrigerators or large screen television sets',
  'Blanquillo': 'A large fish of Florida and the W Indies Caulolatilus chrysops '
               'It is red marked with yellow',
  'Bohemianism': 'The characteristic conduct or methods of a Bohemian',
  'Boswellia': 'a genus of incense yielding trees of North Africa and India',
  'Cardiacle': 'A pain about the heart',
  'Carousal': 'A jovial feast or festival a drunken revel a carouse',
  'Chaldaism': 'An idiom or peculiarity in the Chaldee dialect',
  'Costusroot': 'an annual herb Saussurea costus of the eastern Himalayas '
               'Kashmir having purple florets and a fragrant root that yields '
               'a volatile oil used in perfumery and for preserving furs',
  'Crinatory': 'Crinitory',
  'Diffidence': 'The state of being diffident distrust want of confidence doubt '
               'of the power ability or disposition of others',
  'Diffused': 'Spread abroad dispersed loose flowing diffuse',
  'Disinterestedly': 'In a disinterested manner without bias or prejudice',
  'Dreinte': 'p p of Drench to drown',
  'Drivebolt': 'A drift a tool for setting bolts home',
  'Entirely': 'In an entire manner wholly completely fully as the trace is '
             'entirely lost',
  'Fixable': 'Capable of being fixed',
  'Fleshmonger': 'One who deals in flesh hence a pimp a procurer a pander',
  'Fortuneless': 'Luckless also destitute of a fortune or portion',
  'Frosh': 'a student during his first year in a high school college or '
          'university a freshman',
  'Handover': 'The act of relinquishing property or authority etc to another as '
             'the handover of occupied territory to the original posssessors '
             'the handover of power from the military back to the civilian '
             'authorities',
  'Hipless': 'having hips which are not prominent seeming to have no hips as '
            'slim and hipless of people Opposite of broad hipped',
  'Human': 'Belonging to man or mankind having the qualities or attributes of a '
          'man of or pertaining to man or to the race of man as a human voice '
          'human shape human nature human sacrifices',
  'Impracticable': 'Not practicable incapable of being performed or '
                  'accomplished by the means employed or at command impossible '
                  'as an impracticable undertaking',
  'Indulgential': 'Relating to the indulgences of the Roman Catholic Church',
  'Insignificative': 'Not expressing meaning not significant',
  'Joey': 'Any young animal especially a young kangaroo',
  'Joseph': 'An outer garment worn in the 18th century esp a womans riding '
           'habit buttoned down the front',
  'Kali': 'The glasswort Salsola Kali',
  'Linen': 'Made of linen as linen cloth a linen stocking',
  'Lyric': 'Of or pertaining to a lyre or harp',
  'Manto': 'See Manteau',
  'Melanistic': 'Affected with melanism of the nature of melanism',
  'Misleading': 'Leading astray delusive',
  'Negligence': 'The quality or state of being negligent lack of due diligence '
               'or care omission of duty habitual neglect heedlessness',
  'Neuropterous': 'Neuropteral',
  'Oad': 'See Woad',
  'Otalgy': 'Pain in the ear otalgia',
  'Oxalethyline': 'A poisonous nitrogenous base C6H10N2 obtained indirectly '
                 'from oxamide as a thick transparent oil which has a strong '
                 'narcotic odor and a physiological action resembling that of '
                 'atropine It is probably related to pyridine',
  'Pari ': 'A combining form signifying equal as paridigitate paripinnate',
  'Pathetic': 'Expressing or showing anger passionate',
  'Pectinibranch': 'One of the Pectinibranchiata Also used adjectively',
  'Plongeacutee': 'A slope or sloping toward the front as the plongeacutee of a '
                 'parapet the plongeacutee of a shell in its course',
  'Podo ': 'A combining form or prefix from Gr poys podos foot as podocarp '
          'podocephalous podology',
  'Polythalamous': 'Many chambered applied to shells of Foraminifera and '
                  'cephalopods. See Illust of Nautilus',
  'Presume': 'To assume or take beforehand esp to do or undertake without leave '
            'or authority previously obtained',
  'Pungy': 'A small sloop or shallop or a large boat with sails',
  'Ragery': 'Wantonness',
  'Ranker': 'One who ranks or disposes in ranks one who arranges',
  'Rightwise': 'Righteous',
  'Sabaoth': 'Armies hosts',
  'Scowl': 'To wrinkle the brows as in frowning or displeasure to put on a '
          'frowning look to look sour sullen severe or angry',
  'Self activity': 'The quality or state of being self active self action',
  'Shedding': 'The act of shedding separating or casting off or out as the '
             'shedding of blood',
  'Simial': 'Simian apelike',
  'Sitten': 'p p of Sit for sat',
  'Smartness': 'The quality or state of being smart',
  'Socratically': 'In the Socratic method',
  'Source': 'The act of rising a rise an ascent',
  'Steatite': 'A massive variety of talc of a grayish green or brown color It '
             'forms extensive beds and is quarried for fireplaces and for '
             'coarse utensils Called also potstone lard stone and soapstone',
  'Strainable': 'Capable of being strained',
  'Stroboscope': 'An instrument for studying or observing the successive phases '
                'of a periodic or varying motion by means of light which is '
                'periodically interrupted',
  'Succoteague': 'The squeteague',
  'Tablet': 'A small table or flat surface',
  'Terebenthene': 'Oil of turpentine. See Turpentine',
  'Terrienniak': 'The arctic fox',
  'Transmission': 'The act of transmitting or the state of being transmitted as '
                 'the transmission of letters writings papers news and the '
                 'like from one country to another the transmission of rights '
                 'titles or privileges from father to son or from one '
                 'generation to another',
  'Tunicary': 'One of the Tunicata',
  'Verbarradius vector': 'A straight line or the length of such line connecting '
                        'any point as of a curve with a fixed point or pole '
                        'round which the straight line turns and to which it '
                        'serves to refer the successive points of a curve in a '
                        'system of polar cooumlrdinates. See Cooumlrdinate n',
  'Vesper': 'The evening star Hesper Venus when seen after sunset hence the '
           'evening',
  'Water measurer': 'Any one of numerous species of water the skater. See Skater '
                   'n 2',
  'Weir': 'A dam in a river to stop and raise the water for the purpose of '
         'conducting it to a mill forming a fish pond or the like'
  }