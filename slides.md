---
theme: default
background: /title-bg.jpg
class: text-center
highlighter: shiki
lineNumbers: false
routerMode: 'hash'

info: |
  ## Algo Project

drawings:
  persist: false
# page transition
transition: fade-out | slide-right
css: unocss
title: Algo Project
---

# **BMR & DCR System**

<div
v-motion
:initial="{ x: -80, opacity: 0}"
:enter="{ x: 0, opacity: 1,  scale: 1.5, transition: { delay: 100, duration: 2500 } }"
>
  <span class="color-orange text-xl">
    Group 1
  </span>
</div>

[Source Code](/BMR.c)

---
src: ./pages/contents.md
---

---
src: ./pages/introduction.md
---

---
src: ./pages/objectives.md
---

---
src: ./pages/module.md
---

---
src: ./pages/pseudocode.md
---

---
src: ./pages/flow.md
---

---
layout: cover
background: 'bg3.jpg'
---

# Project Demo

Show you how it works

---
src: ./pages/conclusion.md
---

---
layout: cover
background: 'bg4.jpg'
---

# Q&A

Ask you want to ask ?