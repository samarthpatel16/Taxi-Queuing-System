#include<iostream>
using namespace std;

struct Driver
{
    string name;
    int id;
};

struct LinkedTaxi
{
    int id;
    Driver * drv;
    LinkedTaxi * next;
};

struct Queue
{
    LinkedTaxi * front, *end;
    int numTaxis;
};

int main()
{
    Queue q;
    q.front= NULL;
    q.end= NULL;
    q.numTaxis= 0;






    while (true){
        cout<<"command j to join queue, d to dispatch, x to exit. "<<endl;
        char command;
        cin>> command;


        switch(command) {
            case 'j':

                    Driver *newDrv;
                    newDrv = new Driver;
                    if (newDrv==NULL)
                    {
                        cout<<"Memory allocation failure"<< endl;
                        return -1;
                    }

                    cout <<"give the name of the driver: ";
                    cin>> newDrv->name;
                    cout<<"give the id of driver: ";
                    cin>> newDrv->id;


                    LinkedTaxi *newTaxi;
                    newTaxi = new LinkedTaxi;
                    if (newTaxi == NULL)
                    {
                        cout<<"memory allocation Failure: "<< endl;
                        return -1;
                    }
                    newTaxi-> drv= newDrv;
                    newTaxi-> next = NULL;
                    cout<<"GIve id of taxi: ";
                    cin>>newTaxi->id;

                    if (q.end==NULL)
                    {
                        //taxi queue empty
                        q.front= newTaxi;
                        q.end= newTaxi;
                        q.numTaxis = 1;
                    }

                    else {
                        (q.end)->next = newTaxi;
                        q.end= newTaxi;
                        q.numTaxis++;
                    }

                    break;

            case 'd':

                    if (q.front==NULL)
                    {
                        cout<<"sorry, no taxis available "<<endl;
                    }

                    else {

                        LinkedTaxi * dispatchTaxi;
                        dispatchTaxi= q.front;

                        if (q.front==q.end)
                        {
                            //only one taxi in qqueue
                            q.front=NULL;
                            q.end=NULL;
                            q.numTaxis=0;
                        }

                        else{

                            q.front= (q.front)->next;
                            q.numTaxis--;

                            if (dispatchTaxi != NULL)
                            {
                                cout<<"dispatching taxi with id: "<<dispatchTaxi->id<<endl;

                                if (dispatchTaxi->drv!= NULL)
                                {
                                    delete dispatchTaxi->drv;
                                }

                                delete dispatchTaxi;
                            }

                        }
                    }

                    break;

            case 'x': cout<<"thankyou"<<endl; return 0;

            default: cout<<"invalid command"<<endl;


        }


    }



}