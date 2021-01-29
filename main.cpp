#include <iostream>
#include "string"
using namespace std;
template<class t>
class MyList{
public:
    t *elems;
    int itsSize;
    MyList(int itsSize )
    {
        this->itsSize = itsSize;
        elems = new t[itsSize];
    }
    int getSize()
    {
        return itsSize;
    }
    virtual void addElem (t element) =0;
    virtual t getElem ()=0 ;
    virtual bool isEmpty() = 0;
    virtual bool  isFull() =0 ;
    virtual void  clearItems()=0;
    virtual ~MyList( )
    {
        delete [] elems;
    }


};
template<class t>
class MyStack : public MyList<t>
{
public:
    int countElementInStack;// count how many numbers entered in Stack
    int tempSize;// store the size of queue or stack and decrease When call getElm
    int tempSize2;// store the size of queue or stack and decrease it when use addElem() function
    MyStack(int Size ) : MyList<t>::MyList (Size)
    {
        countElementInStack=0;
        tempSize= Size;
        tempSize2= Size;
    }
    bool isEmpty()
    {
        if(tempSize2 != 0){return false;}
        else{return  true;}
    }
    bool isFull()
    {
        if(countElementInStack != MyList<t>::itsSize){return false;}
        else{return  true;}
    }
    void addElem(t element)
    {

        if(!isFull())
        {
            MyList<t>::elems[tempSize - 1] = element;
            tempSize--;
            countElementInStack++;
        }
        else
        {
            cout<<"The list if full"<<endl;
        }
    }
    t getElem ()
    {
        t element = MyList<t>::elems[0];
        for(int i=0; i < tempSize2 - 1; i++)
        {
            MyList<t>::elems[i] = MyList<t>::elems[i+1];
        }
        tempSize2--;
        return  element;

    }
    void  clearItems()
    {
        delete [] MyList<t>::elems;
    }


};
template<class t>
class MyQueue: public MyList<t>
{
public:
    int countElementInQueue;// count how many numbers entered in Stack
    int tempSize;// store the size of queue or stack and decrease it when use addElem() function
    MyQueue(int Size ) : MyList<t>::MyList (Size)
    {
        countElementInQueue=0;
        tempSize= Size;
    }
    bool isEmpty()
    {
        if(tempSize != 0){return false;}
        else{return  true;}
    }
    bool isFull()
    {
        if(countElementInQueue != MyList<t>::itsSize){return false;}
        else{return  true;}
    }
    void addElem(t element)
    {

        if(!isFull()) {

            MyList<t>::elems[countElementInQueue] = element;
            countElementInQueue++;
        }
        else
        {
            cout<<"The list if full"<<endl;
        }
    }
    t getElem ()
    {
        t element = MyList<t>::elems[0];
        for(int i=0; i < tempSize - 1; i++)
        {
            MyList<t>::elems[i] = MyList<t>::elems[i+1];
        }
        tempSize--;
        return  element;

    }
    void  clearItems()
    {
        delete [] MyList<t>::elems;
    }


};
class Rectangle
{
    int length;
    int width;
public:
    Rectangle()
    {
        length=0;
        width = 0;
    }
    class NegativeSize{};
    Rectangle(int length,int  width )
    {
        if(length<0 ||width<0)
        {
            throw NegativeSize();
        }
        else
        {
            this->length = length;
            this->width = width;
        }


    }

    int getLength(){return  length;}
    int getWidth(){return  width;}
    int getArea(){return length * width;}
    friend ostream& operator<<(ostream& output, Rectangle R)
    {
        output<<"Element-->Length="<<R.length<<",Width="<<R.width<<",Area = "<<R.getArea();
        return output;
    }
    /*friend istream& operator>>(istream& input, Rectangle &R)
    {
        cout<<"Enter length and width space separated:";
        input>>R.length>>R.width;
        return  input;
    }
    */
};
void Check(int size) // check if Size greater than zero or not
{
    if(size<=0){throw "Wrong Size,Please enter the right size";}
}
int main() {
    char choose; // check if we will use stack of queue
    cout<<"Would you like to use a stack or queue (S/Q)?"<<endl;
    cin>>choose;
    if(choose=='S'||choose=='s')
    {
        int SizeOfStack;//express the size of stack
        cout<<"How many item to store?"<<endl;
        bool checkStackSize=false;//check if size is greater than zero or not
        while(!checkStackSize)
        {
            try {
                cin >> SizeOfStack;
                Check(SizeOfStack);
                int chooseTypeOfData;// choose the type of the data that will store on list
                cout<<"Would u like to store integers ,strings ,or rectangles (1,2 or 3)?"<<endl;
                cin>>chooseTypeOfData;
                if(chooseTypeOfData==1) {
                    MyList <int> *listOfStack = new MyStack<int>(SizeOfStack);
                    while (!listOfStack->isFull()) {
                        int element;
                        try
                        {
                            if(!cin>>element)
                            {
                                throw "Wrong String Input-->will enter 0";
                                listOfStack->addElem(0);

                            }

                            cout<<"Enter num:";
                            cin >> element;
                            listOfStack->addElem(element);
                        }
                        catch(const char * message)
                        {
                            cout<<message<<endl;
                            cin.clear();
                            cin.ignore(132,'\n');
                        }



                    }
                    cout<<endl;
                    cout<<"ALL Element"<<endl;
                    while (!listOfStack->isEmpty()) {
                        cout << "Element-->" << listOfStack->getElem() << endl;

                    }
                    listOfStack->clearItems();
                }
                else  if(chooseTypeOfData==2) {
                    MyList <string> *listOfStack = new MyStack<string>(SizeOfStack);

                    while (!listOfStack->isFull()) {
                        cout<<"Enter string:";
                        string element;
                        cin >> element;
                        listOfStack->addElem(element);
                    }
                    cout<<endl;
                    cout<<"ALL Element"<<endl;
                    while (!listOfStack->isEmpty()) {
                        cout << "Element-->" << listOfStack->getElem() << endl;
                    }
                    listOfStack->clearItems();
                }
                else  if(chooseTypeOfData==3) {
                    MyList <Rectangle> *listOfStack = new MyStack<Rectangle>(SizeOfStack);

                    while (!listOfStack->isFull()) {
                        try
                        {
                            cout<<"Enter length and width space separated:";
                            int l,w;cin>>l>>w;
                            // cin >> element;
                            Rectangle element(l,w);
                            listOfStack->addElem(element);
                        }

                        catch(Rectangle::NegativeSize obj)
                        {
                            cout<<"Wrong length or width entering 0 and 0"<<endl;
                            Rectangle el;
                            listOfStack->addElem(el);
                        }

                    }
                    cout<<endl;
                    cout<<"ALL Element"<<endl;
                    while (!listOfStack->isEmpty()) {

                        cout << listOfStack->getElem() << endl << endl;
                    }
                    listOfStack->clearItems();
                }
                checkStackSize=true;
            }
            catch (const  char *message){cout<<message<<endl;}
        }

    }

    else if (choose=='Q'||choose=='q')
    {
        int SizeOfQueue;//Express the size of queue
        cout<<"How many item to store?"<<endl;
        bool checkQueueSize=false;//check if size is greater than zero or not
        while(!checkQueueSize)
        {
            try
            {
                cin >> SizeOfQueue; //Express the size of the queue
                Check(SizeOfQueue);
                int chooseTypeOfData;// Choose the type of the data that will store on list
                cout<<"Would u like to store integers ,strings ,or rectangles (1,2 or 3)?"<<endl;
                cin>>chooseTypeOfData;
                if(chooseTypeOfData==1) {
                    MyList <int> *listOfQueue = new MyQueue<int>(SizeOfQueue);


                    while (!listOfQueue->isFull()) {
                        int element;
                        try
                        {
                            if(!cin>>element)
                            {
                                throw "Wrong String Input-->will enter 0";
                                listOfQueue->addElem(0);

                            }
                            cout<<"Enter num:";
                            cin >> element;
                            listOfQueue->addElem(element);

                        }
                        catch(const char * message)
                        {
                            cout<<message<<endl;
                            cin.clear();
                            cin.ignore(132,'\n');
                        }


                    }
                    cout<<endl;
                    cout<<"ALL Element"<<endl;
                    while (!listOfQueue->isEmpty()) {
                        cout << "Element-->" <<listOfQueue->getElem() << endl;

                    }
                    listOfQueue->clearItems();
                }
                else  if(chooseTypeOfData==2) {
                    MyList <string> *listOfQueue = new MyQueue<string>(SizeOfQueue);

                    while (!listOfQueue->isFull()) {
                        cout<<"Enter string:";
                        string element;
                        cin >> element;
                        listOfQueue->addElem(element);
                    }
                    cout<<endl;
                    cout<<"ALL Element"<<endl;
                    while (!listOfQueue->isEmpty()) {
                        cout << "Element-->" << listOfQueue->getElem() << endl;
                    }
                    listOfQueue->clearItems();
                }
                else  if(chooseTypeOfData==3) {
                    MyList <Rectangle> *listOfQueue = new MyQueue<Rectangle>(SizeOfQueue);

                    while (!listOfQueue->isFull()) {
                        try
                        {
                            cout<<"Enter length and width space separated:";
                            int l,w;cin>>l>>w;
                            // cin >> element;
                            Rectangle element(l,w);
                            listOfQueue->addElem(element);
                        }
                        catch(Rectangle::NegativeSize obj)
                        {
                            cout<<"Wrong length or width entering 0 and 0"<<endl;
                            Rectangle el;
                            listOfQueue->addElem(el);
                        }

                    }
                    cout<<endl;
                    cout<<"ALL Element"<<endl;
                    while (!listOfQueue->isEmpty()) {

                        cout << listOfQueue->getElem() << endl<<endl;
                    }
                    listOfQueue->clearItems();
                }

                checkQueueSize=true;
            }
            catch (const  char *message){cout<<message<<endl;}
        }


    }
}
