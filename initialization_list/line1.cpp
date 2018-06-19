#include <iostream>                                      
                                                         
using namespace std;                                     
                                                         
class Line                                               
{                                                        
   public:                                               
      int getLength( void );                             
      friend void display(Line obj);                              
      friend void line_obj_count();
      Line( int len );           // �򵥵Ĺ��캯��     
      Line( const Line &obj);  // �������캯��           
      ~Line();                     // ��������           
                                                         
   private:
      int p_len;               
      static int obj_count;                      
      int *ptr;                                          
};                                                       
                           
int  Line::obj_count = 0;                              
// ��Ա�������壬�������캯��                            
Line::Line(int len):p_len(len)                                      
//Line::Line(int len)                                 
{                                                        
    cout << "Normal constructor allocating ptr" << endl; 
    obj_count++;                                         
    ptr = new int;
    *ptr = p_len;                                       
}                                                        
                                                     
Line::Line(const Line &obj)                              
{                                                        
    cout << "Copy constructor allocating ptr." << endl;  
    ptr = new int;                                       
   *ptr = *obj.ptr; // copy the value                    
	obj_count++;                                         
}                                                        
                                                         
Line::~Line(void)                                        
{                                                        
    cout << "Freeing memory!" << endl;                   
    delete ptr;                                          
}                                                        
int Line::getLength( void )                              
{                                                        
    return p_len;                                         
}                                                        
                                                         
void display3(Line& obj)                                   
{                                                        
   cout << "display3 : Length of line : " << obj.getLength() <<endl;
}                                                        
void display2(Line* obj)                                   
{                                                        
   cout << "display2 : Length of line : " << obj->getLength() <<endl;
}                                                        
void display(Line obj)                                   
{                                                        
   cout << "display::: Length of line : " << obj.getLength() <<endl;
}                                                        

 void line_obj_count()
{
	cout <<" line count  "<<Line::obj_count<<endl;
}

// �����������                                          
int main( )                                              
{                                                        
   Line line(10);                                        
                                                         

   display2(&line);                  
//   display3(line);                  
                                                     


	line_obj_count();    
   return 0;                                             
}                                                        
