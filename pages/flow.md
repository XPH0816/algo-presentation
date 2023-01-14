# Flowchart

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(1)">Start of Program</span>

  <n-drawer title="Flowchart" :width="screenWidth" :defaultWidth="defaultWidth" :active="show" @close="closeDrawer()">
    <img width="100%" height="100%" :src="url" />
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(2)">Get Information Module</span>

  <n-drawer title="Flowchart" :width="screenWidth" :defaultWidth="defaultWidth" :active="show" @close="closeDrawer()">
    <iframe width="100%" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(3)">Survey Module</span>

  <n-drawer title="Flowchart" :width="screenWidth" :defaultWidth="defaultWidth" :active="show" @close="closeDrawer()">
    <iframe width="100%" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(4)">Calculate Module</span>

  <n-drawer title="Flowchart" :width="screenWidth" :defaultWidth="defaultWidth" :active="show" @close="closeDrawer()">
    <iframe width="100%" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<br />

<n-space>
  <span class="color-gray" @mouseover="showDrawer(5)">Write/Read Disk Module</span>

  <n-drawer title="Flowchart" :width="screenWidth" :defaultWidth="defaultWidth" :active="show" @close="closeDrawer()">
    <iframe width="100%" height="100%" :src="url" frameborder="0"></iframe>
  </n-drawer>
</n-space>

<script setup>
  import { ref } from 'vue'
  const show = ref(false)
  const url = ref('')
  const screenWidth = ref(0)
  const defaultWidth = ref(0)

  function showDrawer(num) {
    screenWidth.value = screen.width
    defaultWidth.value = screenWidth.value
    show.value = true
    if (num == 1) {
      url.value = '/flow1.png'
    } else if (num == 2) {
      url.value = '/flow2.png'
    } else if (num == 3) {
      url.value = '/flow3.png'
    } else if (num == 4) {
      url.value = '/flow4.png'
    } else if (num == 5) {
      url.value = '/flow5.png'
    }
  }

  function closeDrawer() {
    show.value = false
  }

</script>

