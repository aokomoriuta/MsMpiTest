#define MSMPI_NO_DEPRECATE_20

#include <iostream>
#include <boost/mpi.hpp>

int main()
{
    // MPI���iMPI_Init��Finalize������Ă����j
    boost::mpi::environment  env(true);

    // MPI_COMM_WORLD�ŒʐM����悤
    boost::mpi::communicator world;


    // ��������f�[�^
    std::string msg = "Hi";

    // �����ԃv���Z�X����
    if((world.rank()%2) == 0)
    {
        // ��ԃv���Z�X��"Hello"�𑗐M
        world.send( world.rank()+1, 0, std::string("Hello") );
    }   
    // ��ԃv���Z�X�ł�
    else
    {
        // �����ԃv���Z�X���瑗���Ă������������M
        world.recv( world.rank()-1, 0, msg );
    }


    // ���b�Z�[�W��\��
    std::cout << msg << " @ " << world.rank() << std::endl;


    // �I��
    if(world.rank() == 0 )
    {
        system("pause");
    }
    return 0;
}