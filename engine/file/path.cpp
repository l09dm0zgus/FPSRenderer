#include "path.h"

std::string PFE::Path::imagesFolder = "";
std::string PFE::Path::mapsFolder = "";
std::string PFE::Path::rootFolder = "";
std::string PFE::Path::shadersFolder = "";

void PFE::Path::setImagesFolder(std::string folder)
{
	imagesFolder = folder;
}

void PFE::Path::setMapsFolder(std::string folder)
{
	mapsFolder = folder;
}
void PFE::Path::setShadersFolder(std::string folder)
{
	shadersFolder = folder;
}

void PFE::Path::setRootFolder(std::string folder)
{
	rootFolder = folder;
}

std::string PFE::Path::getImageFilePath(std::string imageName)
{
	return rootFolder + imagesFolder+imageName;
}

std::string PFE::Path::getShaderFilePath(std::string shaderName)
{
	return rootFolder + shadersFolder + shaderName;
}

std::string PFE::Path::getMapFilePath(std::string mapName)
{
	return rootFolder + mapsFolder + mapName;
}
