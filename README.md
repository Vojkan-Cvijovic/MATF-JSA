# MATF-JSA
java semantics analyzer school project


class A {
   public int x, y;
   private int z;
   public double f() {
       x = 0; y = 3;
       z = 2;
   }
}

class B {
   public A a;
   public string d;
   public void g() {
     int z = a.x;
     int d; // OK sakrivamo globalno ime
     string h = a.y; // greska y je int, a h je string
     double m = y + d; // OK implicitna konverzija
     a.f();
     int y = a.z; // greska z je private
     int t = a.m; // greska nedefinisano polje
     int s = g(); // greska, g je void
  }
}
