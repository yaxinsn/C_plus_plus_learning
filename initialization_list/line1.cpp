#include <iostream>                                      
                                                         
using namespace std;                                     
                                                         
class Line                                               
{                                                        
   public:                                               
      int getLength( void );                             
      friend void display(Line obj);                              
      friend void line_obj_count();
      //Line():p_len(999);compile error 2019-6-11
      Line();
      Line( int len );           // 简单的构造函数     
      Line( const Line &obj);  // 拷贝构造函数           
      ~Line();                     // 析构函数           
                                                         
   private:
      int p_len;               
      static int obj_count;                      
      int *ptr;                                          
};                                                       
                           
int  Line::obj_count = 0;                              

Line::Line():p_len(999) //默认初始化
{
	cout << "default construtor "<< endl;
	obj_count++;
	ptr = new int;
	*ptr = p_len;
} 

// 成员函数定义，包括构造函数                            
Line::Line(int len):p_len(len)//初始化列表来初始化字段--2019-6-10                              
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

// 程序的主函数                                          
int main( )                                              
{                                                        
   Line line(10);                                        
                                                         
   Line x;

   display2(&line);                  
//   display3(line);                  
                                                     
	display2(&x);

	line_obj_count();    
   return 0;                                             
}                                                        
