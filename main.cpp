#include <iostream>
#include "observable.h"
#include "observer.h"
#include <chrono>
#include <thread>

using namespace std;

int main()
{           // объект для отслеживания файла
            FileMonitor monitor("C:\\CHIKAEED\\untitled6\\monitor.txt");
            FileObserver observer;
           // FileObserver observer2;
            monitor.Attach(&observer);
           // monitor.Attach(&observer2);
                int iter = 1;
                // бесконечный цикл для отслеживания состояния файла
                while (true){
                   // cout << "current iteration: " << iter << endl;
                   // iter++;
                    monitor.checkFile();
                    this_thread::sleep_for( chrono::milliseconds( 1000 ) );
                   // if(iter == 5){
                   //     monitor.Detach(&observer2);
                  //  }
                }


            return 0;
}
