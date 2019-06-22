define e = Character("Eileen")

label start:

  scene bg room
  show eileen happy
  e "You've created a new Ren'Py game."
  e "Once you add a story, pictures, and music, you can release it to the world!"
  e "This boilerplate implements two advanced screens: the Glossary screen and the CG Gallery screen."
  e "Let me first show you the Glossary screen. You can also access it by clicking the Glossary button located at the bottom."

  show screen glossary()
  e "As you can see, there is a list of predefined terms but none of them has been unlocked yet."
  hide screen glossary
  e "Let's add two entries: {i}Acidimetry{/i} and {i}Verbarradius vector{/i} to our unlocked glossary list."
  $ persistent.unlocked_glossary.add('Acidimetry')
  $ persistent.unlocked_glossary.add('Verbarradius vector')

  show screen glossary()
  e "Click on {i}Acidimetry{/i} to view its corresponding definition."
  e "Feel free to scroll to the bottom to check out {i}Verbarradius vector{/i} as well."

  return
