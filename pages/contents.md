---
layout: cover
background: '/bg2.jpg'
---

<div
  v-if="$slidev.nav.currentPage === 2"
  v-motion
  :initial="{ x: -80, opacity: 0}"
  :enter="{ x: 300, opacity: 1, scale: 1.5, transition: { delay: 100, duration: 1300 } }"
>

- Project Background
- Task Assignment
- Pseudocode
- Flowchart
- Project Demo
- Conculsion

</div>
