#ifndef EXGLOBAL_H
#define EXGLOBAL_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <QFile>
#include <QDir>

namespace MinecodeCore
{
template<typename Pointer>
void safedel(Pointer ptr)
{
    delete ptr;
    ptr=nullptr;
}

enum class CaseSensitive
{
    Sensitive,
    Insensitive
};

bool converseBoolean(bool boolean);
QDir* autoDir(const QString &dir);
QFile* autoFile(const QString &file);
QString appendSpaces(int length);
bool isLetter(const QString &input,CaseSensitive sensitive);
}

#define MinecodeKeepLiveBegin {std::condition_variable kl_cv;std::mutex kl_mtx;std::unique_lock <std::mutex> kl_lck(kl_mtx);\
        std::thread kl_thread([&](){kl_mtx.lock(); kl_mtx.unlock();
#define MinecodeKeepLiveEnd	kl_cv.notify_all();});kl_thread.detach(); \
        while (kl_cv.wait_for(kl_lck, std::chrono::milliseconds(100)) == std::cv_status::timeout){qApp->processEvents();}}

#define MinecodeBuildDate "(unknown)"
#define import using namespace

#endif // EXGLOBAL_H
