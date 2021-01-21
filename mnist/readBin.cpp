#include <fstream>
#include <string>
#include <cstring>

void generateImgs(const std::string &filename, const std::string &outDir)
{
	std::ifstream f1(filename, std::fstream::binary);
	f1.seekg(0, f1.end);
	int length = f1.tellg();
	f1.seekg(0, f1.beg);
	char *buffer = new char[length];
	f1.read(buffer, length);
	f1.close();
	int buffcnt = 16;
	int count = 1;
	while (buffcnt + 1 < length)
	{
		std::ofstream pbm;
		std::string imgFilename = "img/" + outDir + "/" + std::to_string(count) + ".pbm";
		pbm.open(imgFilename);
		pbm << "P1\n";
		pbm << "28 28\n";
		for (unsigned int i = 0; i < 28; ++i)
		{
			for (unsigned int j = 0; j < 28; ++j)
			{
				unsigned char byte = buffer[buffcnt];
				pbm << (static_cast<int>(byte) > 0 ? 1: 0);
				++buffcnt;
				if (j < 27) pbm << " ";
			}
			pbm << "\n";
		}
		++count;
		pbm.close();
	}
	delete [] buffer;
}

void generateDataset(const std::string &datasetName, const std::string &labelsName, const std::string &output)
{
	std::ifstream f1 (datasetName, std::fstream::binary);
	std::ifstream f2(labelsName, std::fstream::binary);
	f1.seekg(0, f1.end);
	int length1 = f1.tellg();
	f1.seekg(0, f1.beg);
	char *buffer1 = new char[length1];
	f1.read(buffer1, length1);
	f1.close();
	
	f2.seekg(0, f2.end);
	int length2 = f2.tellg();
	f2.seekg(0, f2.beg);
	char *buffer2 = new char[length2];
	f2.read(buffer2, length2);
	f2.close();
	
	int buffcnt1 = 16;
	int buffcnt2 = 8;
	
	std::ofstream dataset;
	dataset.open(output);
	unsigned char byte;
	while(buffcnt1 + 1 < length1)
	{
		for (unsigned int i = 0; i < 28; ++i)
		{
			for (unsigned int j = 0; j < 28; ++j)
			{
				byte = buffer1[buffcnt1];
				dataset << (static_cast<int>(byte) > 0 ? 1 : 0) << " ";
				++buffcnt1;
			}
		}
		byte = buffer2[buffcnt2];
		++buffcnt2;
		dataset << static_cast<int>(byte) << "\n";
	}
	dataset.close();
	delete [] buffer1;
	delete [] buffer2;
}


int main()
{
	generateImgs("train-images-idx3-ubyte", "train");
	generateImgs("t10k-images-idx3-ubyte", "test");
	generateDataset("train-images-idx3-ubyte", "train-labels-idx1-ubyte", "dataset/train.dataset");
	generateDataset("t10k-images-idx3-ubyte", "t10k-labels-idx1-ubyte", "dataset/test.dataset");
	return 0;
}
