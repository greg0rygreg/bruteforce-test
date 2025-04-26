#include <cstdlib>
#include <cstring>
#include <chrono>
#include <iostream>
int main() {
  auto start = std::chrono::high_resolution_clock::now();
  const char hw_r[] = "Hello World! 12345678910";
  char* hw_b = (char*)malloc(strlen(hw_r) + 1);
  hw_b[0] = '\0'; 
  const char a[] = "1234567890qQwWeErRtTyYuUiIoOpPaAsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM<>,.;:[{()}]\'\"\\=+-_`~!@#$%^&*| ?/";
  int ac = 0;
  int c = 0;
  for(;;){
    if (a[ac] == hw_r[c]) {
      hw_b[c] = a[ac];
      hw_b[c+1] = '\0';
      ac = 0;
      c++;
    }
    if (!(strcmp(hw_b, hw_r))) {
      break;
    }
    ac++;
  }
  free(hw_b);
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> dur = end - start;
  std::cout << "took " << dur.count() * 1000 << " ms to run\n";
  return 0;
}
