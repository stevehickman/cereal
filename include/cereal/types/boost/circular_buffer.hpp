/*! \file boost_circular_buffer.hpp
    \brief Support for types found in \<Boost.Circular Buffer\>
    \ingroup OtherTypes */
/*
  Copyright (c) 2014, Steve Hickman
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of cereal nor the
        names of its contributors may be used to endorse or promote products
        derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL STEVE HICKMAN BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef CEREAL_TYPES_BOOST_CIRCULAR_BUFFER_HPP_
#define CEREAL_TYPES_BOOST_CIRCULAR_BUFFER_HPP_

#include <cereal/cereal.hpp>
#include <boost/circular_buffer.hpp>

namespace cereal
{
  //! Saving for boost::circular_buffer
  template <class Archive, class T, class A> inline
  void save( Archive & ar, boost::circular_buffer<T, A> const & cb )
  {
    ar( make_size_tag( static_cast<size_type>(cb.size()) ) );

    for( auto const & i : cb )
      ar( i );
  }

  //! Loading for boost::circular_buffer
  template <class Archive, class T, class A> inline
  void load( Archive & ar, boost::circular_buffer<T, A> & cb )
  {
    size_type size;
    ar( make_size_tag( size ) );

    cb.resize( static_cast<size_t>( size ) );

    for( auto & i : cb )
      ar( i );
  }
  
    //! Saving for boost::circular_buffer_space_optimized 
  template <class Archive, class T, class A> inline
  void save( Archive & ar, ::boost::circular_buffer_space_optimized <T, A> const & cb )
  {
    ar( make_size_tag( static_cast<size_type>(cb.size()) ) );

    for( auto const & i : cb )
      ar( i );
  }

  //! Loading for boost::circular_buffer_space_optimized 
  template <class Archive, class T, class A> inline
  void load( Archive & ar, ::boost::circular_buffer_space_optimized <T, A> & cb )
  {
    size_type size;
    ar( make_size_tag( size ) );

    cb.resize( static_cast<size_t>( size ) );

    for( auto & i : cb )
      ar( i );
  }
} // namespace cereal

#endif // CEREAL_TYPES_BOOST_CIRCULAR_BUFFER_HPP_
