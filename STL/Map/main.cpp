#include <map>
  #include <iostream>
  #include <string>
  #include <cstdio>


  using namespace std;

  
int  test_clear_many(map <int, string> &m1,int key)
{
	map <int, string>::iterator m1_Iter;
	int tmp_key;
	for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( );)
	{
		cout <<"test_clear_many "<<m1_Iter->first<<": "<<m1_Iter->second<<endl;
		if(m1_Iter->first <= key)
		{
			tmp_key = m1_Iter->first;
			++m1_Iter;
			m1.erase(tmp_key);
			continue;
		}
		++m1_Iter;
	}
	
	return 0;  
}
    int test_print_all(map <int, string> &m1)
  {
	map <int, string>::iterator m1_Iter;
	for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); ++m1_Iter )
	{
		cout <<" "<<m1_Iter->first<<": "<<m1_Iter->second<<endl;
	}		
	return 0;
  }
  int test_insert(map <int, string>& mapx)
  {
	  std::pair<std::map<int,string>::iterator,bool> ret;
	  ret = mapx.insert( pair <int, string>  ( 1, "test1" ) );
	  ret = mapx.insert( pair <int, string>  ( 2, "test2" ) );
	  ret = mapx.insert( pair <int, string>  ( 3, "test3" ) );
	  if(ret.second == false)
	  {
		  printf("%s:%d insert false \n",__func__,__LINE__);
	  }
	  else
	  {
		  
		  printf("%s:%d insert success \n",__func__,__LINE__);
		  ret = mapx.insert( pair <int, string>  ( 3, "test3xx" ) );
		  if(ret.second == false)
		  {
			  printf("%s:%d insert 2 false \n",__func__,__LINE__);
		  }
		  else
		  {
			  printf("%s:%d insert 2 success \n",__func__,__LINE__);
		  }
	  }
	  
	  test_print_all(mapx);
	  return 0;
  }
int test_update(map <int, string>& mapx)
{
	
	  mapx.insert( pair <int, string>  ( 1, "test_update1" ) );
	  mapx.insert( pair <int, string>  ( 2, "test_update2" ) );
	  mapx.insert( pair <int, string>  ( 3, "test_update3" ) );
	  mapx[1] = "abc";
	  
	  test_print_all(mapx);
	  return 0;
}

  
int main( )
{
	map <int, string> m1;
	test_insert(m1);
	printf("%s:%d 	test_update---------------- \n",__func__,__LINE__);
	test_update(m1);
	
	  m1.insert( pair <int, string>  ( 4, "test_update1" ) );
	  m1.insert( pair <int, string>  ( 5, "test_update2" ) );
	  m1.insert( pair <int, string>  ( 6, "test_update3" ) );
	test_clear_many(m1,4);
	
	printf("%s:%d----m1.size() %d----------- \n",__func__,__LINE__,m1.size());
	  test_print_all(m1);
	
}  
  #if 0
  int main( )
  {
	  
      map <int, int> m1, m2, m3;
      map <int, int>::iterator m1_Iter;

      m1.insert ( pair <int, int>  ( 1, 10 ) );
      m1.insert ( pair <int, int>  ( 2, 20 ) );
      m1.insert ( pair <int, int>  ( 3, 30 ) );
      m2.insert ( pair <int, int>  ( 10, 100 ) );
      m2.insert ( pair <int, int>  ( 20, 200 ) );
      m3.insert ( pair <int, int>  ( 30, 300 ) );

   cout << "The original map m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter->second;
      cout   << "." << endl;

   // This is the member function version of swap
   //m2 is said to be the argument map; m1 the target map
   m1.swap( m2 );

   cout << "After swapping with m2, map m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
      cout  << "." << endl;
   cout << "After swapping with m2, map m2 is:";
   for ( m1_Iter = m2.begin( ); m1_Iter != m2.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
      cout  << "." << endl;
   // This is the specialized template version of swap
   swap( m1, m3 );

   cout << "After swapping with m3, map m1 is:";
   for ( m1_Iter = m1.begin( ); m1_Iter != m1.end( ); m1_Iter++ )
      cout << " " << m1_Iter -> second;
      cout   << "." << endl;
}

#endif