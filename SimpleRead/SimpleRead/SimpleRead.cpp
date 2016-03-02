// STL Header
#include <iostream>
// 1. include OpenNI Header
#include "OpenNI.h"

using namespace openni;

int main()
{
	// 2. initialize OpenNI
	OpenNI::initialize();

	//3. open device
	Device device;
	device.open(ANY_DEVICE);

	//4.creat depth stream
	VideoStream streamDepth;
	streamDepth.create(device, SENSOR_DEPTH);
	streamDepth.start();

	VideoFrameRef freamDepth;
	for (int i = 0; i < 100; ++i)
	{
		//5.1 get frame
		streamDepth.readFrame(&freamDepth);

		//5.2 get data array
		const DepthPixel* pDepth;
		pDepth = (const DepthPixel*)freamDepth.getData();

		//5.3output the depth value of center point
		int idx = freamDepth.getWidth() *(freamDepth.getHeight() + 1) / 2;
		std::cout << pDepth[idx] << std::endl;
	}

	system("pause");
	//6. close
	streamDepth.destroy();
	device.close();

	//7. shutdown
	OpenNI::shutdown();

	return 0;
}