//#include <pthread.h>

#include "ofMain.h"
#include "ofApp.h"

//void* thread1(void* pParam);
//void* thread2(void* pParam);
//pthread_mutex_t mutex;


//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

    
//    pthread_t tid1, tid2; // スレッド識別変数
//    
//    pthread_mutex_init(&mutex, NULL);
//    // スレッドの作成
//    pthread_create(&tid1, NULL, thread1, NULL);
//    pthread_create(&tid2, NULL, thread2, NULL);
    

//    // スレッド終了待ち
//    pthread_join(tid1,NULL);
//    pthread_join(tid2,NULL);
//    
//    pthread_mutex_destroy(&mutex);
//    return 0;
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    ofRunApp(new ofApp());
    
}

//void* thread1(void* pParam)
//{
//        //pthread_mutex_lock(&mutex);
//        system("sh ../../../data/open_osc-hub.sh");
//        //pthread_mutex_unlock(&mutex);
//}
//
////スレッド２
//void* thread2(void* pParam)
//{
////        pthread_mutex_lock(&mutex);
//    ofRunApp(new ofApp());
////        pthread_mutex_unlock(&mutex);
//}
