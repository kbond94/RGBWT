#ifndef RGBWT_trackerType_h
#define RGBWT_trackerType_h
#include <Arduino.h>


class RGBWT_trackerType {
	public:
		String api = "";
    String URL = "";
    String Name = "";
    RGBWT_trackerType();
    void setApi(String a);
    void setUrl(String u);
    void setName(String n);
    String getApi();
    String getUrl();
    String getName();

	private:
		
};

//might be better as struct rather than class
/*

typedef struct trackerType{

  String api = "";
  String URL = "";
  String name = "";
  int codeMax;
  int codeMin;

}trackerType

trackerType weather[]

*/


#endif