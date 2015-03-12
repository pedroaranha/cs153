#include "abstractpackage.h"

class TwoDPackage : public AbstractPackage{
protected:
  float first_dimension;
  float second_dimension;

public:
   TwoDPackage(string f, string t, float fd, float sd) :
       AbstractPackage(f, t), first_dimension(fd), second_dimension(sd)
       {}

	virtual float getCharge() const{
    return (first_dimension * second_dimension) * 0.05;
	};

	virtual string getFrom() const{
    return m_from;
	};

  virtual string getTo() const{
    return m_to;
  };

  ~TwoDPackage(){};
};