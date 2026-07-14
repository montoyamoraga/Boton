# Boton

Library for handling buttons with microcontrollers

## Contents

- [.github/](./.github)
- [examples/](./examples/)
- [pico/](./pico/)
- [src/](./src/)
- [.gitignore](./.gitignore)
- [keywords.txt](./keywords.txt)
- [library.properties](./library.properties)
- [LICENSE](./LICENSE)
- [README.md](./README.md): this document.

## Releases

- v0.0.3: July 2026, refactor to make the library compatible with both Arduino boards and Raspberry Pi Pico boards.

## Inspiration

When building a sequencer, I knew i wanted it to have all the usual suspects including buttons and knobs, and I wanted to have a short library where I could abstract all the behaviors I wanted on them.

I built this library, and then it stayed dormant while I entered a PhD program and I took a deep dive on electronics and PCBs, and teaching object-oriented programming, but not writing libraries for a while.

Now in 2026 I knew I wanted to expand my library to be compatible with the Raspberry Pi Pico boards I am researching, so I added more folders and abstractions, in order to make this library agnostic, and to be able to include it on different projects.
