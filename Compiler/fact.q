// Factorial function
fact(n) {
  if (n == 0) { return 1; }
  else { return n*fact(n-1); } // n != 0
}

// Main routine
main() {
  var n;
  printf("N? ");
  scanf("%d", n);
  printf("%d! = %d\n", n, fact(n));
}
