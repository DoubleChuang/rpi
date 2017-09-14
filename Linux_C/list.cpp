#include<iostream>  
#include <list>  
#include <algorithm>  
using namespace  std;  
int main()  
{  
    list<char> lit;   
    //用法和向量一样，  
    //list是一个类模板，template，char是链表里对象的类型，lit是创建的一个对象；  
    //链表可以再头尾两端插入,是双向的；  
  
    lit.push_back('a');  
    lit.push_back('b');  
    lit.push_front('a');  
    lit.push_front('e');  
    lit.push_front('f');  
    lit.push_front('b');  
    lit.push_front('b');  
  
    list<char>::iterator it;  //定义一个list的迭代器，类似一个纸箱链表的指针，但是比一般的指针好用，里面用到了好多重载操作；  
    list<char>::iterator it1;    
    list<char>::iterator it2;    
    for(it=lit.begin();it!=lit.end();it++)  
    {  
        cout<<*it<<"  ";  
    }  
    cout<<endl;  
    //-----------链表可以从两端删除-------------------   
    lit.pop_back();    
    lit.pop_front();  
    for(it=lit.begin();it!=lit.end();it++)  
    {  
        cout<<*it<<"  ";  
    }  
    cout<<endl;  
    //-------------删除所有的a---------------------------------  
    //lit.remove('a');  //删除所有的a;  
  
    for(it=lit.begin();it!=lit.end();it++)  
    {  
        cout<<*it<<"  ";  
    }  
    cout<<endl;  
    //-------------移除连续且相同的a，只剩下一个;--------------------------------  
    lit.unique();  //移除连续且相同的a，只剩下一个;  
  
    for(it=lit.begin();it!=lit.end();it++)  
    {  
        cout<<*it<<"  ";  
    }  
    cout<<endl;  
    list<char> lit1;  
    lit1.push_back('g');  
    lit1.push_back('h');  
    lit1.push_back('i');  
    lit1.push_back('k');  
    for(it1=lit1.begin();it1!=lit1.end();it1++)  
    {  
        cout<<*it1<<"  ";  
    }  
    cout<<endl;  
    //-------------将一个链表插入到另一个链表---------------------------------  
    it1=find(lit.begin(),lit.end(),'f');  //先的找到要插入的位置，在该位置的前一个插入；  
    ////lit.splice(it1,lit1); //将第二个链表插入到第一个链表中；合并后的链表就没了，因为传的是&；  
    for(it=lit.begin();it!=lit.end();it++)  
    {  
        cout<<*it<<"  ";  
    }  
    cout<<endl;  
    //------在链表lit中的it前插入lit1中的一个元素it1；在f之前插入k-----  
    //-----拿下来之后那个元素就没有了-------------------  
    it=find(lit.begin(),lit.end(),'f');  
    it1=find(lit1.begin(),lit1.end(),'k');  
    lit.splice(it,lit1,it1);  
    //-------------把链表中的一段插入到另一个链表中---------------------------------  
    //把链表lit1中的[it-----it1)段的字符插入到lit的it2指针前；  
    it=find(lit1.begin(),lit1.end(),'h');  
    it1=find(lit1.begin(),lit1.end(),'k');  
    it2=find(lit.begin(),lit.end(),'f');  
    lit.splice(it2,lit1,it,it1);   
    // ----void merge(list& x); //将x合并到*this 身上。两个lists 的内容都必须先经过递增归并排序。  
    lit.sort();   //对两个排序进行归并排序；  
    lit1.sort();  
    lit.merge(lit1);  
    //-----------将list里的数据倒序排列---------------  
    lit.reverse();  
    for(it=lit.begin();it!=lit.end();it++)  
    {  
        cout<<*it<<"  ";  
    }  
    cout<<endl;  
    for(it1=lit1.begin();it1!=lit1.end();it1++)  
    {  
        cout<<*it1<<"  ";  
    }  
    cout<<endl;  
    #ifdef _WIN32
        system("pause");  
    #endif
    return 0;  
}  