package alpha;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

class MyAddTests {

  @Test
  void addition() {
    MyAdd myadd = new MyAdd();
    assertEquals(myadd.add(3, 2), 5);
  }

}