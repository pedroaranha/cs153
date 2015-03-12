//Author: Pedro Aranha - Section B

#include <iostream>
#include <string>
#include "gmatrix.h"
using namespace std;

GMatrix::GMatrix(int c, int r, int s, int d){
  int temp;

  if(c < 0){
    c = c * -1;
  }
  if(r < 0){
    r = r * -1;
  }

  m_cols = c;
  m_rows = r;
  m_data = new int*[c];

  for(int x = 0; x < c; x++){
    m_data[x] = new int[r];
  }

  for(int i = 0; i < c; i++){
    for(int j = 0; j < r; j++){
      if(i == 0 && j == 0){
        m_data[i][j] = s;
        temp = s;
      }
      else{
        temp += d;
        m_data[i][j] = temp;
      }
    }
  }
}

GMatrix::~GMatrix(){
  for(int k = 0; k < m_cols; k++){
    delete [] m_data[k];
  }
  delete [] m_data;
}

const GMatrix& GMatrix::operator=(const GMatrix& rhs){
  if(this != &rhs){

    for(int k = 0; k < m_cols; k++)
      delete [] m_data[k];
    delete [] m_data;

    m_cols = rhs.m_cols;
    m_rows = rhs.m_rows;
    m_data = new int*[m_cols];

    for(int x = 0; x < m_cols; x++){
      m_data[x] = new int[m_rows];
    }

    for(int l = 0; l < m_cols; l++){
      for(int m = 0; m < m_rows; m++){
        m_data[l][m] = rhs.m_data[l][m];
      }
    }
  }
  return *this;
}

GMatrix::GMatrix(const GMatrix& rhs){
  m_cols = 1;
  m_rows = 1;
  m_data = new int*[1];
  m_data[0] = new int[1];

  *this = rhs;
}

std::ostream& operator<< (std::ostream& out, const GMatrix& gm){
  for(int y = 0; y < gm.m_cols; y++){
    for(int z = 0; z < gm.m_rows; z++){
      out << gm.m_data[y][z] << " ";
    }
    out << endl;
  }
  return out;
}
