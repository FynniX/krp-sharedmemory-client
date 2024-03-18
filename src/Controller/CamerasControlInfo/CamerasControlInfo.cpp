#include "CamerasControlInfo.h"

void CamerasControlInfo::SetVehicle(int vehicle)
{
    view->selectedVehicle = vehicle;
    buffer->write();
}

void CamerasControlInfo::SetCamera(int camera)
{
    view->selectedCamera = camera;
    buffer->write();
}