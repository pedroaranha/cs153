#include "abstractpackage.h"

class FourDPackage : public AbstractPackage{
protected:
  float first_dimension;
  float second_dimension;
  float third_dimension;
  float fourth_dimension;
  float weight;

public:
   FourDPackage(string f, string t, float fd, float sd, float td, float fod, float w) :
       AbstractPackage(f, t), first_dimension(fd), second_dimension(sd), third_dimension(td), fourth_dimension(fod), weight(w)
       {}

	virtual float getCharge() const{
    float volume = first_dimension * second_dimension * third_dimension * fourth_dimension;

    return (volume * 0.01) + (weight * 3.14) + 42.42;
	};

	virtual string getFrom() const{
    return m_from;
	};

  virtual string getTo() const{
    return m_to;
  };

  virtual ~FourDPackage(){
    AbstractPackage::~AbstractPackage();
  };
};