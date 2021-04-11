#include "lmdbwrap.h"
#include <iostream>

namespace cconnect2 {
  namespace cconnect {

    LmdbWarp::LmdbWarp() {
      int rc;
      rc = mdb_env_create(&env);
      rc = mdb_env_open(env, "./testdb", 0, 0664);
    }

    int LmdbWarp::LmdbDrop() {
      int rc;
      rc = mdb_txn_begin(env, NULL, 0, &txn);
      rc = mdb_dbi_open(txn, NULL, 0, &dbi);
      // Drop mdb_drop (MDB_txn *txn, MDB_dbi dbi, int del)
      rc = mdb_txn_commit(txn);
      mdb_dbi_close(env, dbi);

      return rc;
    }

    int LmdbWarp::LmdbPut() {
      int rc;
      rc = mdb_txn_begin(env, NULL, 0, &txn);
      rc = mdb_dbi_open(txn, NULL, 0, &dbi);
      // Put
      rc = mdb_txn_commit(txn);
      mdb_dbi_close(env, dbi);

      return rc;
    }

    int LmdbWarp::LmdbGet() {
      int rc;
      rc = mdb_txn_begin(env, NULL, 0, &txn);
      rc = mdb_dbi_open(txn, NULL, 0, &dbi);
      // Get
      rc = mdb_txn_commit(txn);
      mdb_dbi_close(env, dbi);

      return 0;
    }

    int LmdbWarp::LmdbDel() {
      int rc;
      rc = mdb_txn_begin(env, NULL, 0, &txn);
      rc = mdb_dbi_open(txn, NULL, 0, &dbi);
      // Get
      rc = mdb_txn_commit(txn);
      mdb_dbi_close(env, dbi);

      return 0;
    }

    LmdbWarp::~LmdbWarp() {
      int rc;
      mdb_env_close(env);
    }

  }  // namespace cconnect
}  // namespace cconnect2