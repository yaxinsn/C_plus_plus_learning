#include <iostream>                                      
                                                         
using namespace std;                                     
                                                         
class Line                                               
{                                                        
   public:                                               
      int getLength( void );                             
      friend void display(Line obj);                              
      friend void line_obj_count();
      Line( int len );           // ¼òµ¥µÄ¹¹Ôìº¯Êý     
      Line( const Line &obj);  // ¿½±´¹¹Ôìº¯Êý           
      ~Line();                     // Îö¹¹º¯Êý           
                                                         
   private:
      int p_len;               
      static int obj_count;                      
      int *ptr;                                          
};                                                       
                           
int  Line::obj_count = 0;                              
// ³ÉÔ±º¯Êý¶¨Òå£¬°üÀ¨¹¹Ôìº¯Êý                            
Line::Line(int len):p_len(len)  
/* ¿¿len¿¿¿¿Line¿¿p_len¿¿¿¿¿¿¿¿¿¿¿¿¿ */                                    
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
#if 1                                                        
namespace    display3 {                                                      
	void display(Line& obj)                                   
	{                                                        
   		cout << "display3 : Length of line : " << obj.getLength() <<endl;
	}                      
}                           
       
#endif
namespace    display2{                                                      
 void line_obj_count()
{
	cout <<" 222222222222 "<<endl;
}
}                           
#if 1
namespace    display1 {      
                                                
	void display(Line& obj)                                   
	{                                                        
   		cout << "display1 11111111:------- Length of line : " << obj.getLength() <<endl;
	}         
	namespace display4 {
		
		void display(Line& obj)                                   
		{                                                        
   			cout << "display44444444 :------- Length of line : " << obj.getLength() <<endl;
		}         
	}             
}    
#endif                       

//using namespace display2;
// ³ÌÐòµÄÖ÷º¯Êý                                          
int main( )                                              
{                                                        
   Line line(10);                                        
display1::display(line);                  
//display2::display(line);                  
display3::display(line);                  
display1::display4::display(line);                  
//	line_obj_count();   
	return 0;                                             
}                                                        
