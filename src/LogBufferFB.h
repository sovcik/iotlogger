#ifndef __LOGBUFFERFB_H__
#define __LOGBUFFERFB_H__

#include <FS.h>
#include "LogBuffer.h"
#include "FileBuffer.h"

#define BUFFER_MAX_RECORDS  50

class LogBufferFB : public LogBuffer {
    protected:
        FileBuffer<LogRecord> *fb;   // file containing log entries, each fixed length
        char* logFName;

    public:
        LogBufferFB(const char* logFName, uint16_t capacity=50);
        virtual ~LogBufferFB();
        int begin(int clear = 0) override;
        void stop() override;
        inline int isReady() override {return fb->isReady();};
        inline int isEmpty() override {return fb->isEmpty();};
        
        inline unsigned int size() override {return fb->size();};
        int write(LogRecord *rec) override;
        int read(LogRecord *);
        
};

#endif