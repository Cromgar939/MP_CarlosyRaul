/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 24 October 2023, 14:00
 */

#include "Kmer.h"
using namespace std;

Kmer::Kmer(int k)
{
    if(k<=0)
    {
        throw invalid_argument("Fuera de rango");
    }else
    {
        for(int i=0; i<k; i++)
        {
            _text+=MISSING_NUCLEOTIDE;
        }
    }
}

Kmer::Kmer(const string& text)
{
   if(text.empty())
   {
    throw invalid_argument("String vacio");
   }
   else
   {
    this->_text=text;
   }
}

int Kmer::getK() const
{
 return this->_text.size();
}

int Kmer::size() const
{
    getK();
}

string Kmer::toString() const
{
  return this->_text;
}

const char& Kmer::at(int index) const
{
  if(index>this->_text.size())
  {
    throw out_of_range("Fuera de rango");
  }
  else
  {
    return _text[index];
  }
}

char& Kmer::at(int index)
{
  if(index>this->_text.size() || index<0)
  {
    throw out_of_range("Fuera de rango");
  }
  else
  {
    return _text[index];
  }
}

void Kmer::normalize(const string& validNucleotides)
{
   
    for(int i=0; i<validNucleotides.size(); i++)
    {
         char nuc=_text(i);
         if(IsValidNucleotide(nuc,validNucleotides))
         {
             this->_text(i)=toupper(nuc);
         }
         else
         {
             this->_text(i)=MISSING_NUCLEOTIDE;
         }
    }
}

Kmer Kmer::complementary(const string& nucleotides, const string& complementaryNucleotides) const
{
  if(nucleotides.size()!=complementaryNucleotides.size())
  {
    throw out_of_range("Tamanos imcompatibles");
  }
  else
  {
      Kmer complement;
      for(int i=0; i<this->_text.size(); i++)
      {
          for(int j=0; j<nucleotides.size(); i++)
          {
              if(this->_text.at(i)==nucleotides.at(j))
              {
                  complement._text += complementaryNucleotides(j); 
              }
          }
      }
  }
  return complementaryNucleotides;
}

bool IsValidNucleotide(char nucleotide, const string& validNucleotides)
{
  bool valid=false;

  for(int i=0; i<validNucleotides.size(); i++)
  {
    if(validNucleotides.at(i)==nucleotide)
    {
      valid=true;
    }
  }
  return valid;
}

void ToLower(Kmer& kmer)
{
  for(int i=0; i<Kmer.size(); i++)
  {
      tolower(Kmer.at(i));
  }
}

void ToUpper(Kmer& kmer)
{
  for(int i=0; i<Kmer.size(); i++)
  {
      toupper(Kmer.at(i));
  }
}