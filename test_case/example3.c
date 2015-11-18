void function(int a, int b) {
   char buffer1[5];
   char buffer2[3];
   int *ret;
   printf("return address is %p\n", __builtin_return_address(0));
   printf("buffer1 address is %p\n", buffer1);
   printf("buffer2 address is %p\n", buffer2);
   printf("ret address is %p\n", &ret);
   ret = buffer1 + 24;
   printf("ret+24 address is %p\n", ret);
   //printf("ret address is %p\n", ret);
   (*ret) += 5;
}

void main() {
  int x;

  x = 0;
  function(1,2);
  x = 1;
  printf("%d\n",x);
}