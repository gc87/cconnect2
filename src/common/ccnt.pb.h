// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ccnt.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_ccnt_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_ccnt_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3015000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3015006 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_ccnt_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_ccnt_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_ccnt_2eproto;
::PROTOBUF_NAMESPACE_ID::Metadata descriptor_table_ccnt_2eproto_metadata_getter(int index);
namespace ccnt {
class Test;
struct TestDefaultTypeInternal;
extern TestDefaultTypeInternal _Test_default_instance_;
}  // namespace ccnt
PROTOBUF_NAMESPACE_OPEN
template<> ::ccnt::Test* Arena::CreateMaybeMessage<::ccnt::Test>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace ccnt {

// ===================================================================

class Test PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ccnt.Test) */ {
 public:
  inline Test() : Test(nullptr) {}
  virtual ~Test();
  explicit constexpr Test(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Test(const Test& from);
  Test(Test&& from) noexcept
    : Test() {
    *this = ::std::move(from);
  }

  inline Test& operator=(const Test& from) {
    CopyFrom(from);
    return *this;
  }
  inline Test& operator=(Test&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Test& default_instance() {
    return *internal_default_instance();
  }
  static inline const Test* internal_default_instance() {
    return reinterpret_cast<const Test*>(
               &_Test_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Test& a, Test& b) {
    a.Swap(&b);
  }
  inline void Swap(Test* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Test* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Test* New() const final {
    return CreateMaybeMessage<Test>(nullptr);
  }

  Test* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Test>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Test& from);
  void MergeFrom(const Test& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Test* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ccnt.Test";
  }
  protected:
  explicit Test(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    return ::descriptor_table_ccnt_2eproto_metadata_getter(kIndexInFileMessages);
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdsFieldNumber = 1,
  };
  // repeated string ids = 1;
  int ids_size() const;
  private:
  int _internal_ids_size() const;
  public:
  void clear_ids();
  const std::string& ids(int index) const;
  std::string* mutable_ids(int index);
  void set_ids(int index, const std::string& value);
  void set_ids(int index, std::string&& value);
  void set_ids(int index, const char* value);
  void set_ids(int index, const char* value, size_t size);
  std::string* add_ids();
  void add_ids(const std::string& value);
  void add_ids(std::string&& value);
  void add_ids(const char* value);
  void add_ids(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& ids() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_ids();
  private:
  const std::string& _internal_ids(int index) const;
  std::string* _internal_add_ids();
  public:

  // @@protoc_insertion_point(class_scope:ccnt.Test)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> ids_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_ccnt_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Test

// repeated string ids = 1;
inline int Test::_internal_ids_size() const {
  return ids_.size();
}
inline int Test::ids_size() const {
  return _internal_ids_size();
}
inline void Test::clear_ids() {
  ids_.Clear();
}
inline std::string* Test::add_ids() {
  // @@protoc_insertion_point(field_add_mutable:ccnt.Test.ids)
  return _internal_add_ids();
}
inline const std::string& Test::_internal_ids(int index) const {
  return ids_.Get(index);
}
inline const std::string& Test::ids(int index) const {
  // @@protoc_insertion_point(field_get:ccnt.Test.ids)
  return _internal_ids(index);
}
inline std::string* Test::mutable_ids(int index) {
  // @@protoc_insertion_point(field_mutable:ccnt.Test.ids)
  return ids_.Mutable(index);
}
inline void Test::set_ids(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:ccnt.Test.ids)
  ids_.Mutable(index)->assign(value);
}
inline void Test::set_ids(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:ccnt.Test.ids)
  ids_.Mutable(index)->assign(std::move(value));
}
inline void Test::set_ids(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  ids_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:ccnt.Test.ids)
}
inline void Test::set_ids(int index, const char* value, size_t size) {
  ids_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:ccnt.Test.ids)
}
inline std::string* Test::_internal_add_ids() {
  return ids_.Add();
}
inline void Test::add_ids(const std::string& value) {
  ids_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:ccnt.Test.ids)
}
inline void Test::add_ids(std::string&& value) {
  ids_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:ccnt.Test.ids)
}
inline void Test::add_ids(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  ids_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:ccnt.Test.ids)
}
inline void Test::add_ids(const char* value, size_t size) {
  ids_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:ccnt.Test.ids)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Test::ids() const {
  // @@protoc_insertion_point(field_list:ccnt.Test.ids)
  return ids_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Test::mutable_ids() {
  // @@protoc_insertion_point(field_mutable_list:ccnt.Test.ids)
  return &ids_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace ccnt

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_ccnt_2eproto
