//
// Created by Fynn Haupt on 05.06.2023.
//

#include <iostream>
#include <windows.h>
#include "MappedBuffer.h"

template<typename MappedBufferT>
MappedBuffer<MappedBufferT>::MappedBuffer(std::string BUFFER_NAME) : BUFFER_NAME(std::move(BUFFER_NAME)),
                                                                     BUFFER_SIZE_BYTES(sizeof(MappedBufferT)) {}

template<typename MappedBufferT>
void MappedBuffer<MappedBufferT>::create() {
    this->file = CreateFileMappingA(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, this->BUFFER_SIZE_BYTES,
                                    this->BUFFER_NAME.c_str());
    if (this->file == nullptr)
        throw std::runtime_error("Couldn't create file mapping (" + this->BUFFER_NAME + ").");
}

template<typename MappedBufferT>
void MappedBuffer<MappedBufferT>::open() {
    this->file = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, this->BUFFER_NAME.c_str());
    if (this->file == nullptr)
        throw std::runtime_error("Couldn't open file mapping (" + this->BUFFER_NAME + ").");
}

template<typename MappedBufferT>
MappedBufferT *MappedBuffer<MappedBufferT>::view() {
    if (this->buffer != nullptr)
        return this->buffer;

    this->buffer = (MappedBufferT *) MapViewOfFile(this->file,
                                                   FILE_MAP_ALL_ACCESS,
                                                   0,
                                                   0,
                                                   this->BUFFER_SIZE_BYTES);

    if (this->buffer == nullptr)
        throw std::runtime_error("Couldn't map view of file (" + this->BUFFER_NAME + ").");

    return this->buffer;
}

template<typename MappedBufferT>
void MappedBuffer<MappedBufferT>::write() {
    if (this->buffer == nullptr)
        throw std::runtime_error("View of file is nullptr (" + this->BUFFER_NAME + ").");

    if (!FlushViewOfFile(this->buffer, this->BUFFER_SIZE_BYTES))
        throw std::runtime_error("Couldn't flush view of file (" + this->BUFFER_NAME + ").");
}

template<typename MappedBufferT>
void MappedBuffer<MappedBufferT>::close() {
    UnmapViewOfFile(this->buffer);
    this->buffer = nullptr;
    CloseHandle(this->file);
    this->file = nullptr;
}

template<typename MappedBufferT>
std::string MappedBuffer<MappedBufferT>::getBufferName() {
    return this->BUFFER_NAME;
}