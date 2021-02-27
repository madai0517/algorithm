import java.util.Random;

class Bubble {
  private static final int N = 20;
  private static int[] sort = new int[N];

  private static void bubbleSort() {
    boolean flag = false;
    do {
      flag = false;
      for (int i = 0; i < N - 1; i++) {
        if (sort[i] > sort[i + 1]) {
          flag = true;
          int j = sort[i];
          sort[i] = sort[i + 1];
          sort[i + 1] = j;
        }
      }
    } while (flag);
  }

  public static void main(String[] args) {
    Random r = new Random();
    System.out.println("before:");
    for (int i = 0; i < N; i++) {
      sort[i] = r.nextInt(100);
      System.out.print(sort[i] + " ");
    }

    bubbleSort();

    System.out.println("\nafter:");
    for (int i = 0; i < N; i++) {
      System.out.print(sort[i] + " ");
    }

  }
}