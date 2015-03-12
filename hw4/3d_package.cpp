#include "abstractpackage.h"

class ThreeDPackage : public AbstractPackage{
protected:
  float first_dimension;
  float second_dimension;
  float third_dimension;
  float weight;

public:
   ThreeDPackage(string f, string t, float fd, float sd, float td, float w) :
       AbstractPackage(f, t), first_dimension(fd), second_dimension(sd), third_dimension(td), weight(w)
       {}

	virtual float getCharge() const{
    float volume = first_dimension * second_dimension * third_dimension;

    return (volume * 0.02) + (weight * 2.71);
	};

	virtual string getFrom() const{
    return m_from;
	};

  virtual string getTo() const{
    return m_to;
  };

  virtual ~ThreeDPackage(){
    AbstractPackage::~AbstractPackage();
  };
};