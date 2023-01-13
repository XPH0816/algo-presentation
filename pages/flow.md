# Flowchart

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(1)">Start of Program</span>

  <n-drawer title="Flowchart" :active="show" @close="closeDrawer()">
    <iframe width="1400" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(2)">Get Information Module</span>

  <n-drawer title="Flowchart" :active="show" @close="closeDrawer()">
    <iframe width="1400" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(3)">Survey Module</span>

  <n-drawer title="Flowchart" :active="show" @close="closeDrawer()">
    <iframe width="1400" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(4)">Calculate Module</span>

  <n-drawer title="Flowchart" :active="show" @close="closeDrawer()">
    <iframe width="1400" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(5)">Write/Read Disk Module</span>

  <n-drawer title="Flowchart" :active="show" @close="closeDrawer()">
    <iframe width="1400" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<script setup>
  import { ref } from 'vue'
  const show = ref(false)
  const url = ref('')

  function showDrawer(num) {
    if (num == 1) {
      show.value = true
      url.value = 'http://localhost:3030/flow1.png'
    } else if (num == 2) {
      show.value = true
      url.value = 'http://localhost:3030/flow2.png'
    } else if (num == 3) {
      show.value = true
      url.value = 'http://localhost:3030/flow3.png'
    } else if (num == 4) {
      show.value = true
      url.value = 'http://localhost:3030/flow4.png'
    } else if (num == 5) {
      show.value = true
      url.value = 'http://localhost:3030/flow5.png'
    }
  }

  function closeDrawer() {
    show.value = false
  }

</script>

