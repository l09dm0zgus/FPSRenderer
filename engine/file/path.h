#ifndef PATH_H
#define PATH_H
#include <iostream>
namespace PFE
{
	class Path
	{
	public:
		static void setShadersFolder(std::string folder);
		static void setImagesFolder(std::string folder);
		static void setMapsFolder(std::string folder);
		static void setRootFolder(std::string folder);
		static std::string getShaderFilePath(std::string shaderName);
		static std::string getMapFilePath(std::string mapName);
		static std::string getImageFilePath(std::string imageName);
	private:
		static std::string shadersFolder;
		static std::string imagesFolder;
		static std::string mapsFolder;
		static std::string rootFolder;

	};
}
#endif // PATH_H

