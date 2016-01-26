#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char * RV_string;

struct Event                                              //浜嬩欢
{
int eventNumber;                                          //浜嬩欢搴忓彿
struct Parameter *parameters;                             //鍙傛暟瀵硅薄          
};

typedef struct Parameter                                  //鍙傛暟瀵硅薄
{
struct ParameterPair *pair;                               //鍙傛暟瀵?int size;                                                 //鍙傛暟瀵逛釜鏁?}*Total;

Total empty,temp,collection;

struct ParameterPair                                      //鍙傛暟瀵?{
RV_string name;                                           //鍙傛暟鍚?double value;                                             //鍙傛暟鍊?};

struct all
{
Total *paras;
int number;
int capacity;                                             //瀹归噺
}*total;

typedef struct HashNode                                   //鍝堝笇缁撶偣
{
double value;                                             //鍙傛暟鍊?
int state;                                                //鑷姩鏈虹姸鎬?int i;                                                    //缁撶偣鎵€鍦ㄥ搱甯岃〃瀵瑰眰鏁?int initial;                                              //缁撶偣鏄惁鍒濆鍖?              
struct HashMap* nextMap;                                  //涓嬩竴灞傚搱甯岃〃
}*Node;

struct HashMap                                            //鍝堝笇琛?{
int number;                                               //鍝堝笇缁撶偣涓暟   
int capacity;                                             //鍝堝笇琛ㄥ閲?
Node *node;                                               //琛ㄤ腑鐨勫搱甯岀粨鐐?}*hm,*h;

int symbol=-1;

void f(int a);
void g(float b);
void l(int a,float b);

struct HashMap* RV_hashMap_create(int i);
int RV_hashMap_set(struct Parameter p,int s);
int RV_hashMap_state(struct Parameter p);
int RV_Hash(double x);   
struct Parameter RV_compatible(struct Parameter p1,struct Parameter p2);
void RV_start(struct Event e,RV_string name);
int RV_max(struct Parameter p);
int RV_trans(int old,RV_string name);
int RV_exist(struct Parameter p);
int RV_equal(struct Parameter p1,struct Parameter p2);
int RV_more(struct Parameter *p,int size,struct Parameter q);
int RV_existPair(struct Parameter p,struct ParameterPair pair);
int RV_existType(struct Parameter p,RV_string type);
double RV_getValue(struct Parameter p,RV_string type);
struct HashMap* RV_resize(struct HashMap *this,int newCapacity);
struct all* RV_resizeTotal(int newCapacity);
int RV_existCompatible(struct Parameter p,int number);
void RV_hashMap_modify(struct Parameter p,int old,int new);
int RV_isCompatible(struct Parameter p1,struct Parameter p2);

int main()
{

hm=RV_hashMap_create(1000);
empty=(struct Parameter *)calloc(1,sizeof(struct Parameter));                
empty->size=0;
total=(struct all*)calloc(1,sizeof(struct all));
total->paras=(struct Parameter*)calloc(100,sizeof(struct Parameter));
total->number=1;
total->capacity=100;
total->paras[0]=(struct Parameter*)calloc(1,sizeof(struct Parameter));
total->paras[0]=empty;

struct Event *e1,*e2;

int i=0;
for(i=0;i<100;i++)
{
l(3+i,4.1+0.1*i);

e1=(struct Event *)calloc(1,sizeof(struct Event));

e1->parameters=(struct Parameter *)calloc(1,sizeof(struct Parameter));
e1->parameters->pair=(struct ParameterPair *)calloc(2,sizeof(struct ParameterPair));
e1->parameters->pair[0].name="int";
e1->parameters->pair[0].value=3+i;
e1->parameters->pair[1].name="float";
e1->parameters->pair[1].value=4.1+0.1*i;
e1->parameters->size=2;
e1->eventNumber=0+6*i;
printf("i: %d number: %d value: %f value: %f\n",i,e1->eventNumber,e1->parameters->pair[0].value,e1->parameters->pair[1].value);
RV_start(*e1,"useL");

f(3+i);

e1=(struct Event *)calloc(1,sizeof(struct Event));

e1->parameters=(struct Parameter *)calloc(1,sizeof(struct Parameter));
e1->parameters->pair=(struct ParameterPair *)calloc(1,sizeof(struct ParameterPair));
e1->parameters->pair[0].name="int";
e1->parameters->pair[0].value=3+i;
e1->parameters->size=1;

e1->eventNumber=1+6*i;
printf("i: %d number: %d value: %f\n",i,e1->eventNumber,e1->parameters->pair[0].value);
RV_start(*e1,"useF");

g(4.1+0.1*i);

e1=(struct Event *)calloc(1,sizeof(struct Event));

e1->parameters=(struct Parameter *)calloc(1,sizeof(struct Parameter));
e1->parameters->pair=(struct ParameterPair *)calloc(1,sizeof(struct ParameterPair));
e1->parameters->pair[0].name="float";
e1->parameters->pair[0].value=4.1+0.1*i;
e1->parameters->size=1;
e1->eventNumber=2+6*i;
printf("i: %d number: %d value: %f\n",i,e1->eventNumber,e1->parameters->pair[0].value);

RV_start(*e1,"useG");

l(5+i,4.9+0.1*i);

e1=(struct Event *)calloc(1,sizeof(struct Event));

e1->parameters=(struct Parameter *)calloc(1,sizeof(struct Parameter));
e1->parameters->pair=(struct ParameterPair *)calloc(2,sizeof(struct ParameterPair));
e1->parameters->pair[0].name="int";
e1->parameters->pair[0].value=5+i;
e1->parameters->pair[1].name="float";
e1->parameters->pair[1].value=4.9+0.1*i;
e1->parameters->size=2;
e1->eventNumber=3+6*i;
printf("i: %d number: %d value: %f value: %f\n",i,e1->eventNumber,e1->parameters->pair[0].value,e1->parameters->pair[1].value);
RV_start(*e1,"useL");


f(5+i);

e1=(struct Event *)calloc(1,sizeof(struct Event));

e1->parameters=(struct Parameter *)calloc(1,sizeof(struct Parameter));
e1->parameters->pair=(struct ParameterPair *)calloc(1,sizeof(struct ParameterPair));
e1->parameters->pair[0].name="int";
e1->parameters->pair[0].value=5+i;
e1->parameters->size=1;
e1->eventNumber=4+6*i;
printf("i: %d number: %d value: %f\n",i,e1->eventNumber,e1->parameters->pair[0].value);
RV_start(*e1,"useF");



g(4.9+0.1*i);

e1=(struct Event *)calloc(1,sizeof(struct Event));

e1->parameters=(struct Parameter *)calloc(1,sizeof(struct Parameter));
e1->parameters->pair=(struct ParameterPair *)calloc(1,sizeof(struct ParameterPair));
e1->parameters->pair[0].name="float";
e1->parameters->pair[0].value=4.9+0.1*i;
e1->parameters->size=1;
e1->eventNumber=5+6*i;
printf("i: %d number: %d value: %f\n",i,e1->eventNumber,e1->parameters->pair[0].value);
RV_start(*e1,"useG");

}

return 0;
}

void f(int a)
{
}

void g(float b)
{
}

void l(int a,float b)
{
}

void RV_start(struct Event e,RV_string name)                                             
{
    symbol=-1;
    int i=0;
    int j=0;
    temp=(struct Parameter *)calloc(1,sizeof(struct Parameter));   
    collection=(struct Parameter *)calloc(total->number,sizeof(struct Parameter));
    int number=0;
    for(i;i<total->number;i++)
    {          
        //if(e.parameters->size==1)
        //printf("name %s value: %f\n",e.parameters->pair[0].name,e.parameters->pair[0].value);
        if(RV_isCompatible(*(e.parameters),*(total->paras[i]))==0)
        { 
           //printf("here\n");
        }
        else
        {  
              
            *temp=RV_compatible(*(e.parameters),*(total->paras[i]));
               
             
           if(RV_existCompatible(*temp,number)!=1)
           { 
              collection[number]=*temp;
              number++;             
           
              int max=RV_max(*temp);
              int state=RV_hashMap_state(*temp);
              int new; 
              //printf("max: %d state: %d size: %d\n",max,state,temp->size);     
              if(state<=0) 
              {   
                 new=RV_trans(max,name);
                 RV_hashMap_set(*temp,new);
              }
              else if(state>0)
              { 
                 new=RV_trans(max,name);
                 //printf("new: %d\n",new);  
                 RV_hashMap_modify(*temp,state,new);
                 
              } 
              
           }
           
        } 
             
    }
    //printf("hett\n");
    //printf("size: %d\n",temp->size); 
    //printf("number: %d\n",number);
    
    for(i=0;i<number;i++)
    {
        //printf("this\n");
        if(RV_exist(collection[i])==0)
        {
            
            int j;
            total->paras[total->number]=(struct Parameter*)calloc(1,sizeof(struct Parameter));
            total->paras[total->number]->pair=(struct ParameterPair*)calloc(collection[i].size,sizeof(struct ParameterPair));

            for(j=0;j<collection[i].size;j++)
            { 
                //printf("number: %d size: %d\n",number,collection[i].size);
                total->paras[total->number]->pair[j]=collection[i].pair[j];
                
            }
           
            total->paras[total->number]->size=collection[i].size; 
            total->number++;  
            if(total->number==total->capacity)
            {
               total=RV_resizeTotal(2*(total->capacity)); 
            } 
        }
    }
}

int RV_existCompatible(struct Parameter p,int number)
{
    int i=0;
    for(i;i<number;i++)
    {
        if(RV_equal(collection[i],p)==1)
        return 1;
    }
    return 0;
}

struct all* RV_resizeTotal(int newCapacity)
{
    
    int oldCapacity = total->capacity;
    int i;
    struct all* new=(struct all*)calloc(1,sizeof(struct all));
    new->paras=(struct Parameter*)calloc(oldCapacity,sizeof(struct Parameter));
    new->number=total->number;
    new->capacity=newCapacity;
    for(i=0;i<oldCapacity;i++)
    {       
       new->paras[i]=total->paras[i];       
    }  
    for(i=oldCapacity;i<newCapacity;i++)
    {
       new->paras[i]=(struct Parameter*)calloc(1,sizeof(struct Parameter));   
    }   
    return new;
}

int RV_isCompatible(struct Parameter p1,struct Parameter p2)
{
    
    if(p1.size==0&&p2.size==0)
    return 1;
    if(p1.size==0)
    return 1;
    if(p2.size==0)
    return 1;
 
    if(RV_less(p1,p2)==1)  
    return 1;
    if(RV_less(p2,p1)==1)
    return 1;      

    if(RV_equal(p1,p2)==1)
    return 1;

    //printf("%f\n",total[1].pair[0].value);
    int i=0;
    for(i;i<p1.size;i++)
    {
        
        if(RV_existType(p2,p1.pair[i].name)==1)
        {
            //printf("name %s value: %f\n",p1.pair[i].name,RV_getValue(p2,p1.pair[i].name));
            if(p1.pair[i].value!=RV_getValue(p2,p1.pair[i].name))
            { 
            //printf("there\n");
            return 0;
              
            }
        }   
    } 
    return 1;
}

struct Parameter RV_compatible(struct Parameter p1,struct Parameter p2)
{
   
    
    if(p1.size==0&&p2.size==0)
    return *empty;
    if(p1.size==0)
    return p2;
    if(p2.size==0)
    return p1;
 
    if(RV_less(p1,p2)==1)  
    return p2;
    if(RV_less(p2,p1)==1)
    return p1;      
    
    if(RV_equal(p1,p2)==1)
    return p1;
    //printf("%f\n",total[1].pair[0].value);
  
    int i=0;
    int j=0;
    int count=0;
    for(i;i<p1.size;i++)
    {
        if(RV_existType(p2,p1.pair[i].name)==1)
        {
            
            if(p1.pair[i].value==RV_getValue(p2,p1.pair[i].name))
            count++;
        }   
    } 
    

    
    int size=p1.size+p2.size-count;
    
    temp=(struct Parameter *)calloc(1,sizeof(struct Parameter));
    temp->pair=(struct ParameterPair *)calloc(size,sizeof(struct ParameterPair)); 
    
    temp->size=p1.size+p2.size-count;
    count=0;
    for(i=0;i<p1.size;i++)
    {
           
        if(RV_existType(p2,p1.pair[i].name)==1)
        {
            if(p1.pair[i].value==RV_getValue(p2,p1.pair[i].name))
            {
                temp->pair[count].value=p1.pair[i].value;
                temp->pair[count].name=p1.pair[i].name;
               
                count++;
            }   
        }   
        else
        {  
            temp->pair[count].value=p1.pair[i].value;
            temp->pair[count].name=p1.pair[i].name;
            count++;
        } 
    } 
    
             

    for(i=0;i<p2.size;i++)
    {
        if(RV_existPair(*temp,p2.pair[i])==0)
        {
            temp->pair[count].value=p2.pair[i].value;
            temp->pair[count].name=p2.pair[i].name;   
               
            count++;
        }  
    }
    
    if(count==2&&temp->pair[0].name=="float")
    {
        
        RV_string name=temp->pair[0].name; 
        temp->pair[0].name=temp->pair[1].name; 
        temp->pair[1].name="float"; 
        double value=temp->pair[0].value; 
        temp->pair[0].value=temp->pair[1].value; 
        temp->pair[1].value=value;     
    }
    
    return *temp; 
}

int RV_max(struct Parameter p)
{
    int i=0;
    int count=0;  
    int max=0;
   
    for(i;i<total->number;i++)
    {
        if(RV_less(*(total->paras[i]),p)==1||RV_equal(*(total->paras[i]),p)==1)
        count++;     
    }
    
    //printf("number: %d count: %d\n",total->number,count);   
  
    struct Parameter *lessArray=(struct Parameter *)calloc(count,sizeof(struct Parameter));
    count=0;
    
    for(i=0;i<total->number;i++)
    {
        if(RV_less(*(total->paras[i]),p)==1||RV_equal(*(total->paras[i]),p)==1)
        {
            lessArray[count]=*(total->paras[i]); 
            count++;
        }     
    }
    
    int size=count;
    for(i=0;i<count;i++)  
    {
        //printf("hi size: %d\n",lessArray[i].size);  
        if(RV_more(lessArray,size,lessArray[i])==1)
        {
            
            if(lessArray[i].size==0)
            return 1;
            else
            {
               //printf("i: %d here\n",i);   
               return RV_hashMap_state(lessArray[i]);
            }     
        }     
    }
    
}

int RV_more(struct Parameter *p,int size,struct Parameter q)
{
    int i=0;
    for(i;i<size;i++)
    {   
         
        if(RV_less(p[i],q)==0&&RV_equal(p[i],q)==0) 
        return 0; 
    }
    return 1;     
}

int RV_trans(int old,RV_string name)
{
    
    if(old==1&&strcmp(name,"useL")==0)
    {
       printf("Lused\n");  
       return 2; 
    }
    if(old==2&&strcmp(name,"useF")==0)
    {
       printf("Fused\n");  
       return 3; 
    }
    if(old==3&&strcmp(name,"useG")==0)
    {
       printf("Gused\n");
       printf("fail\n");  
       return 4;
    } 
    return old; 
}

int RV_exist(struct Parameter p)
{
    int i=0;
    for(i;i<total->number;i++)
    {
        if(RV_equal(p,*(total->paras[i]))==1)
        return 1; 
    }
    return 0;
}

int RV_existPair(struct Parameter p,struct ParameterPair pair)
{
    int i;
    for(i=0;i<p.size;i++)
    {
       if(pair.name==p.pair[i].name&&pair.value==p.pair[i].value)
       return 1;
    }
    return 0;
}

int RV_existType(struct Parameter p,RV_string type)
{
    
    //printf("%d\n",p.pair[0].value);
    int i=0;
    for(i;i<p.size;i++)
    {
       if(strcmp(p.pair[i].name,type)==0)
       return 1;  
    }  
    return 0;
}

double RV_getValue(struct Parameter p,RV_string type)
{
    int i=0;
    for(i;i<p.size;i++)
    {
       if(strcmp(p.pair[i].name,type)==0)
       return p.pair[i].value;  
    }    
    return 0;
}

int RV_equal(struct Parameter p1,struct Parameter p2)                          //鍒ゆ柇涓や釜鍙傛暟瀵硅薄鏄惁鐩哥瓑
{
    if(p1.size!=p2.size)
    return 0;
    else
    {
        int i;    
        for(i=0;i<p1.size;i++)
        {
            if(p1.pair[i].name!=p2.pair[i].name||p1.pair[i].value!=p2.pair[i].value)
            return 0;  
        } 
   
    }  
    return 1;     
}

int RV_less(struct Parameter p1,struct Parameter p2)
{
    if(p1.size==0)
    return 1;
    if(p1.size>=p2.size)
    return 0;
    else
    {
       int i;
       for(i=0;i<p1.size;i++)
       {
           if(RV_existPair(p2,p1.pair[i])==0)
           return 0;
       } 
       return 1;
    } 
}

struct HashMap* RV_hashMap_create(int size)
{
    int i;
    struct HashMap *hashmap=(struct HashMap*)calloc(1,sizeof(struct HashMap));
    hashmap->capacity=size;
    hashmap->node=(struct HashNode*)calloc(size,sizeof(struct HashNode));
    hashmap->number=0;
    return hashmap;
}

int RV_hashMap_set(struct Parameter p,int s)
{
    
    int i=0;
    int size=p.size;
    int number; 
    h=hm;
    
    struct HashMap *hashmap;
    if(size<1)
    return 0; 
    while(size!=0)
    {
         number=0;
         int hash=RV_Hash(p.pair[i].value)%(h->capacity); 
         while(h->node[hash]!=NULL&&h->node[hash]->value!=p.pair[i].value)
         {      
                   
            hash=(hash+1)%(h->capacity);
            number++;
         }
         if(h->node[hash]!=NULL&&h->node[hash]->value==p.pair[i].value&&size==1&&h->node[hash]->state!=0)
         return 0;
        
        
         if(h->node[hash]==NULL||h->node[hash]!=NULL&&h->node[hash]->value==p.pair[i].value)
         {
            if(h->node[hash]==NULL)
            {
               h->node[hash]=(struct HashNode *)calloc(1,sizeof(struct HashNode));
               h->number++;
            }
            h->node[hash]->value=p.pair[i].value;
            
            //printf("thathash: %d\n",hash);
            //printf("hash: %d number: %d size: %d\n",hash,h->number,size);       
            if(size==1)
            {
               h->node[hash]->initial=1;
               h->node[hash]->state=s;
               //printf("insert: hash: %d state %d\n",hash,s);
            } 
            else if(size==2)
            {
               symbol=hash;
               //printf("symbol: %d\n",symbol);
            }  
            //printf("symbol: %d\n",symbol); 
            //printf("number %d,capacity: %f\n",h->number,0.75*(h->capacity)); 
            if(h->number>=0.75*(h->capacity))
            {
               
               //printf("number: %d,capacity: %d\n",h->number,h->capacity);
               h=RV_resize(h,2*(h->capacity));
               //printf("number: %d,capacity: %d\n",h->number,h->capacity);
               hash=RV_Hash(p.pair[i].value)%(h->capacity);   
               while(h->node[hash]!=NULL&&h->node[hash]->value!=p.pair[i].value)
               {
                  hash=(hash+1)%(h->capacity);  
               }
               
               if(i==0)
               hm=h;
               else if(i==1)
               {
                 //printf("hash: %d\n",symbol);    
                 hm->node[symbol]->nextMap=h;
               }        
            }   
         } 
         
        
         
         i++; 
         size--;
         
         if(size!=0) 
         {
            if(h->node[hash]->nextMap==NULL)
            h->node[hash]->nextMap=RV_hashMap_create(1000);
            h=h->node[hash]->nextMap;  
            
         }   
    }
    
    return 0;
}
 
int RV_hashMap_state(struct Parameter p)
{   
    
    int i=0;                                                             
    int size=p.size;
    int number=0;
    h=hm;
    if(size<1)
    return 0; 
    while(size!=0)
    {
         
         int hash=RV_Hash(p.pair[i].value)%(h->capacity);
         //printf("hash: %d\n",hash); 
         while(h->node[hash]!=NULL&&h->node[hash]->value!=p.pair[i].value&&number<h->capacity)
         {            
            hash=(hash+1)%(h->capacity);
            number++;
         }
          
         if(number>=h->capacity)
         {
            return 0; 
         }         
         if(h->node[hash]==NULL)
         {
            //printf("%d %d %d\n",size,hash,h->node[hash].isInitial);
            return -1;
         }
         
         if(h->node[hash]!=NULL&&h->node[hash]->value==p.pair[i].value&&size==1)
         {
            return h->node[hash]->state; 
         } 
         if(h->node[hash]!=NULL&&h->node[hash]->value==p.pair[i].value&&size!=1)
         {
            //printf("thishash: %d\n",hash);
            h=h->node[hash]->nextMap;
            if(h==NULL)
            return -1; 
         } 
         size--;
         i++;      
    }
   
    return -1;
}

void RV_hashMap_modify(struct Parameter p,int old,int new)
{   
    
    int i=0;                                                             
    int size=p.size;
    int number=0;
    h=hm;
    if(size<1)
    return ; 
    while(size!=0)
    {
         
         int hash=RV_Hash(p.pair[i].value)%(h->capacity);
        
         while(h->node[hash]!=NULL&&h->node[hash]->value!=p.pair[i].value&&number<h->capacity)
         {            
            hash=(hash+1)%(h->capacity);
            number++;
         }  
             
         if(number>=h->capacity)
         {
            return ; 
         }         
         if(h->node[hash]==NULL)
         {
            return ;
         }
         
         if(h->node[hash]->value==p.pair[i].value&&size==1)
         {
            if(h->node[hash]->state==old)
            h->node[hash]->state=new;
            return ;
         } 
         if(h->node[hash]->value==p.pair[i].value&&size!=1)
         {
            h=h->node[hash]->nextMap;
         } 
         size--;
         i++; 
           
    }
   
    return ;
}


int RV_Hash(double h)                                                                  //Hash鍑芥暟
{    
    //unsigned int x = h;                                                                //鐢变簬瑕佹棤绗﹀彿鍙崇Щ,宸﹁竟琛?0
    //x ^= (x >> 20) ^ (x >> 12);
    //return x ^ (x >> 7) ^ (x >> 4);
    return (100*h)/33;
}

struct HashMap* RV_resize(struct HashMap *this,int newCapacity)
{
    int i;
    int oldCapacity = this->capacity;
 
    struct HashMap *hashmap=(struct HashMap*)calloc(1,sizeof(struct HashMap));
   
    hashmap->capacity=newCapacity;
    hashmap->node=(struct HashNode*)calloc(newCapacity,sizeof(struct HashNode));
    hashmap->number=this->number;      

    for(i=0;i<oldCapacity;i++)
    {     
       if(this->node[i]!=NULL)
       {
          
          int hash=RV_Hash(this->node[i]->value);
          if(hash%oldCapacity==hash%newCapacity)
          {
              while(hashmap->node[hash%oldCapacity]!=NULL)
              {
                 hash=hash+1;
              }
              if(hashmap->node[hash%oldCapacity]==NULL)
              {
                 hashmap->node[hash%oldCapacity]=this->node[i];
              } 
          }  
           
          else
          {
              
              while(hashmap->node[hash%newCapacity]!=NULL)
              {
                 hash=hash+1; 
              }
              if(hashmap->node[hash%newCapacity]==NULL)
              {
                
                 hashmap->node[hash%newCapacity]=this->node[i];  
              }
          }     
       }
             
    } 
   
    return hashmap;
}
