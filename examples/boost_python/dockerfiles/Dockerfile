FROM charming/python:latest

RUN set -o xtrace \
  && : ===  DOWNLOAD SLIM SOURCE === \
    && mkdir -p /usr/src/boost \
    && cd /usr/src/boost \
    && git clone https://github.com/boostorg/boost.git . \
    && git submodule update --init \
      libs/array \
      libs/assert \
      libs/bind \
      libs/concept_check \
      libs/config \
      libs/conversion \
      libs/core \
      libs/detail \
      libs/filesystem \
      libs/foreach \
      libs/function \
      libs/functional \
      libs/graph \
      libs/integer \
      libs/iterator \
      libs/lexical_cast \
      libs/math \
      libs/move \
      libs/mpl \
      libs/multi_index \
      libs/numeric/conversion \
      libs/optional \
      libs/parameter \
      libs/predef \
      libs/preprocessor \
      libs/property_map \
      libs/python \
      libs/range \
      libs/serialization \
      libs/smart_ptr \
      libs/static_assert \
      libs/throw_exception \
      libs/tuple \
      libs/type_traits \
      libs/typeof \
      libs/unordered \
      libs/utility \
      libs/wave \
      libs/container \
      tools/build \
      tools/inspect

RUN set -o xtrace \
  && : === BUILD === \
    && boost_version="1.57.0" \
    && cd /usr/src/boost \
    && git checkout boost-${boost_version} \
    && ./bootstrap.sh \
      --with-python=/opt/python-2.7/bin/python \
      --prefix=/opt/boost \
    && ./b2 headers \
    && ./b2 --with-python install