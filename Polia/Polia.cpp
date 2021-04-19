#include <stdexcept>;
using namespace std;

class Vektor{
private: long *aPole;
		 unsigned int aRozsah;

		 void copy(const Vektor &zdroj){
			 aPole = NULL;
			 aPole = new long[aRozsah];
			 for (unsigned int i = 0; i < aRozsah; i++){
				 aPole[i] = zdroj.aPole[i];
			 }
		 }

		 void zmaz(){
			 if (aPole){
				 delete[]aPole;
				 aPole = NULL;
				 aRozsah = 0;
			 }
		 }
public:  Vektor(unsigned int pRozsah) : aRozsah(pRozsah), aPole(aRozsah != 0 ? new long[aRozsah] : NULL){
			 for (unsigned int i = 0; i < aRozsah; i++){
				 aPole[i] = 0;
			 }
}
		 Vektor(const Vektor & zdroj){
			 copy(zdroj);
		 }

		 long &operator[](unsigned int index){
			 if (index < 0 || index >= aRozsah){
				 throw logic_error("Zadany zly index");
				 return aPole[index];
			 }
		 }

		 Vektor &operator=(const Vektor &zdroj){
			 if (&zdroj != this){
				 zmaz();
				 copy(zdroj);
			 }
			 return *this;
		  }

		 ~Vektor(void){
			 zmaz();
		 }
};



//};