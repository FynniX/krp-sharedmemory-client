//
// Created by Fynn Haupt on 02.11.2023.
//

#include <iostream>
#include "SharedFileIn.h"
#include "SharedFileOut.h"
#include "MappedBuffer.cpp"
#include "CameraSet.h"

void CameraSet::connect()
{
    try
    {
        this->controller.open();
    }
    catch (std::runtime_error e)
    {
        this->controller.create();
    }

    this->controller.view()->m_id = -1;
}

void CameraSet::setIsControlled(int isControlled)
{
    try
    {
        CameraSet_t *view = this->controller.view();
        view->m_id = view->m_id + 1;
        view->isControlled = isControlled;
        this->controller.write();
    }
    catch (std::runtime_error e)
    {
    }
}

void CameraSet::setSelectedVehicle(int selectedVehicle)
{
    try
    {
        CameraSet_t *view = this->controller.view();
        view->m_id = view->m_id + 1;
        view->selectedVehicle = selectedVehicle;
        this->controller.write();
    }
    catch (std::runtime_error e)
    {
    }
}

void CameraSet::setSelectedCamera(int selectedCamera)
{
    try
    {
        CameraSet_t *view = this->controller.view();
        view->m_id = view->m_id + 1;
        view->selectedCamera = selectedCamera;
        this->controller.write();
    }
    catch (std::runtime_error e)
    {
    }
}

void CameraSet::disconnect()
{
    CameraSet_t *view = this->controller.view();
    view->m_id = view->m_id + 1;
    view->isControlled = 0;
    this->controller.write();
    this->controller.close();
}