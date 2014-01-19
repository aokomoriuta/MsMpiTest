#define MSMPI_NO_DEPRECATE_20

#include <iostream>
#include <boost/mpi.hpp>

int main()
{
    // MPI環境（MPI_InitとFinalizeをやってくれる）
    boost::mpi::environment  env(true);

    // MPI_COMM_WORLDで通信するよう
    boost::mpi::communicator world;


    // 交換するデータ
    std::string msg = "Hi";

    // 偶数番プロセスから
    if((world.rank()%2) == 0)
    {
        // 奇数番プロセスへ"Hello"を送信
        world.send( world.rank()+1, 0, std::string("Hello") );
    }   
    // 奇数番プロセスでは
    else
    {
        // 偶数番プロセスから送られてきた文字列を受信
        world.recv( world.rank()-1, 0, msg );
    }


    // メッセージを表示
    std::cout << msg << " @ " << world.rank() << std::endl;


    // 終了
    if(world.rank() == 0 )
    {
        system("pause");
    }
    return 0;
}