#ifndef RGBWT_display_h
#define RGBWT_display_h

class RGBWT_display{
  public:
    String top = "";
    String bottom = "";
    String bottomList[4];
    RGBWT_display();
    RGBWT_display(String t, String b);
    RGBWT_display(String t, String bo1, String bo2, String bo3, String bo4);
    void changeTop(String nt);
    void changeBottom(String nb);
};

#endif